// daten.js – Spieldaten-Verwaltung (IndexedDB, Ordner-/ZIP-Import, GOG-ISO9660-Leser, Prüfsummen-Prüfung)
// für DSA 3: Schatten über Riva (Browser-Edition)

(function() {
    'use strict';

    var DB_NAME = 'riva-spieldaten';
    var DB_VERSION = 1;
    var STORE_NAME = 'dateien';
    var META_KEY = '__meta__';

    // Pflichtdateien laut Starter/spiele.json ("riva")
    var PFLICHT_DATEIEN = ['RIVA.EXE', 'DATA/RIVA.ALF'];

    // Bekannte Größe (2.477.899 Bytes) und SHA-256-Prüfsumme der deutschen Originalversion V1.12 (RIVA.EXE)
    var SOLL_RIVA_EXE_GROESSE = 2477899;
    var BEKANNTE_VERSIONEN = {
        '98cc39096b99e1518a214317026e9be0e64584dad74bc0c30b8b1e5075f35705': 'DSA 3: Schatten über Riva – Deutsche CD-Version V1.12 (GOG / Original-CD)'
    };

    var IGNORIERTE_ENDUNGEN = [
        '.BAT', '.COM', '.DLL', '.DOC', '.TXT', '.PDF', '.HTML', '.HTM',
        '.LNK', '.ICO', '.BMP', '.PNG', '.JPG', '.CONF', '.INI', '.INST', '.INS', '.CUE', '.LOG', '.MSG'
    ];

    function openDB() {
        return new Promise(function(resolve, reject) {
            var req = indexedDB.open(DB_NAME, DB_VERSION);
            req.onupgradeneeded = function(ev) {
                var db = ev.target.result;
                if (!db.objectStoreNames.contains(STORE_NAME)) {
                    db.createObjectStore(STORE_NAME);
                }
            };
            req.onsuccess = function(ev) { resolve(ev.target.result); };
            req.onerror = function(ev) { reject(ev.target.error || new Error('IndexedDB konnte nicht geöffnet werden.')); };
        });
    }

    async function sha256Hex(uint8) {
        if (!window.crypto || !window.crypto.subtle) return '';
        var hashBuf = await window.crypto.subtle.digest('SHA-256', uint8);
        var arr = new Uint8Array(hashBuf);
        var hex = '';
        for (var i = 0; i < arr.length; i++) {
            hex += arr[i].toString(16).padStart(2, '0');
        }
        return hex;
    }

    function normalizeGameRelPath(rawPath) {
        var p = String(rawPath || '').replace(/\\/g, '/').replace(/^\/+/, '');
        var parts = p.split('/').filter(Boolean);
        if (parts.length === 0) return '';
        var upParts = parts.map(function(s) { return s.toUpperCase(); });

        if (upParts.indexOf('DOSBOX') !== -1 || upParts.indexOf('__SUPPORT') !== -1 || upParts.indexOf('CLOUD_SAVES') !== -1) {
            return '';
        }

        var knownFolders = ['DATA', 'GAMES', 'MUSIC', 'TEMP', 'CTEMP'];
        for (var i = 0; i < upParts.length - 1; i++) {
            if (knownFolders.indexOf(upParts[i]) !== -1) {
                return upParts.slice(i).join('/');
            }
        }
        var base = upParts[upParts.length - 1];
        if (/^TRACK\d+\.OGG$/i.test(base)) {
            return 'MUSIC/' + base;
        }
        var rootFiles = [
            'RIVA.EXE', 'GAME.GOG', 'RIVA.CFG',
            'SCHWEIF.EXE', 'TRAIL.EXE', 'STARTRAI.EXE', 'STARTRAIL.EXE',
            'SCHICKM.EXE', 'BLADE.EXE', 'ARKANIA3.EXE', 'SHADOWS.EXE', 'ROA3.EXE'
        ];
        if (rootFiles.indexOf(base) !== -1) {
            return base;
        }
        if (upParts.length >= 2) {
            return upParts.slice(-2).join('/');
        }
        return base;
    }

    function shouldImportFile(normPath) {
        if (!normPath) return false;
        var base = normPath.split('/').pop();
        if (!base || base.startsWith('.')) return false;
        if (base === 'GAME.GOG') return true;
        if (base.endsWith('.EXE')) {
            return (
                base === 'RIVA.EXE' ||
                base === 'ARKANIA3.EXE' ||
                base === 'SHADOWS.EXE' ||
                base === 'ROA3.EXE' ||
                base === 'SCHWEIF.EXE' ||
                base === 'TRAIL.EXE' ||
                base === 'STARTRAI.EXE' ||
                base === 'STARTRAIL.EXE' ||
                base === 'SCHICKM.EXE' ||
                base === 'BLADE.EXE'
            );
        }
        for (var i = 0; i < IGNORIERTE_ENDUNGEN.length; i++) {
            if (base.endsWith(IGNORIERTE_ENDUNGEN[i])) return false;
        }
        return true;
    }

    // Mode2/2352 bzw. Mode1/2048 ISO9660-Leser für game.gog (extrahiert DATA/* und GAMES/* per Blob.slice)
    async function extractFromGogIsoBlob(blob, existingMap, onProgress) {
        var extracted = {};
        if (!blob || blob.size < 40000) return extracted;

        async function readSlice(offset, length) {
            var ab = await blob.slice(offset, offset + length).arrayBuffer();
            return new Uint8Array(ab);
        }

        var sectorSize = 2352;
        var dataOffset = 24;
        var pvd = await readSlice(16 * 2352 + 24, 2048);
        var sig = String.fromCharCode(pvd[1], pvd[2], pvd[3], pvd[4], pvd[5]);
        if (sig !== 'CD001') {
            pvd = await readSlice(16 * 2352 + 16, 2048);
            sig = String.fromCharCode(pvd[1], pvd[2], pvd[3], pvd[4], pvd[5]);
            if (sig === 'CD001') {
                dataOffset = 16;
            } else {
                pvd = await readSlice(16 * 2048, 2048);
                sig = String.fromCharCode(pvd[1], pvd[2], pvd[3], pvd[4], pvd[5]);
                if (sig !== 'CD001') return extracted;
                sectorSize = 2048;
                dataOffset = 0;
            }
        }

        async function readIsoBytes(lba, byteLen) {
            var out = new Uint8Array(byteLen);
            if (sectorSize === 2048) {
                var direct = await readSlice(lba * 2048, byteLen);
                out.set(direct);
                return out;
            }
            var totalSectors = Math.ceil(byteLen / 2048);
            var chunkSectors = 2048;
            var written = 0;
            for (var s = 0; s < totalSectors; s += chunkSectors) {
                var count = Math.min(chunkSectors, totalSectors - s);
                var raw = await readSlice((lba + s) * sectorSize, count * sectorSize);
                for (var k = 0; k < count && written < byteLen; k++) {
                    var take = Math.min(2048, byteLen - written);
                    var start = k * sectorSize + dataOffset;
                    out.set(raw.subarray(start, start + take), written);
                    written += take;
                }
            }
            return out;
        }

        var view = new DataView(pvd.buffer, pvd.byteOffset, pvd.byteLength);
        var rootLba = view.getUint32(156 + 2, true);
        var rootLen = view.getUint32(156 + 10, true);

        var entries = [];
        async function scanDir(dirLba, dirLen, prefix) {
            var data = await readIsoBytes(dirLba, dirLen);
            var dv = new DataView(data.buffer, data.byteOffset, data.byteLength);
            var pos = 0;
            while (pos < dirLen) {
                var reclen = data[pos];
                if (reclen === 0) {
                    pos = ((pos >> 11) + 1) << 11;
                    continue;
                }
                var flba = dv.getUint32(pos + 2, true);
                var flen = dv.getUint32(pos + 10, true);
                var flags = data[pos + 25];
                var nlen = data[pos + 32];
                var name = '';
                for (var i = 0; i < nlen; i++) {
                    name += String.fromCharCode(data[pos + 33 + i]);
                }
                var semi = name.indexOf(';');
                if (semi !== -1) name = name.substring(0, semi);
                if (name.endsWith('.')) name = name.slice(0, -1);
                name = name.toUpperCase();

                if (name && name.charCodeAt(0) > 1) {
                    var full = prefix ? (prefix + '/' + name) : name;
                    if (flags & 2) {
                        if (full === 'DATA' || full === 'GAMES') {
                            await scanDir(flba, flen, full);
                        }
                    } else {
                        entries.push({ path: full, lba: flba, size: flen });
                    }
                }
                pos += reclen;
            }
        }

        await scanDir(rootLba, rootLen, '');

        for (var idx = 0; idx < entries.length; idx++) {
            var e = entries[idx];
            if (!e.path.startsWith('DATA/') && !e.path.startsWith('GAMES/')) continue;
            var base = e.path.split('/').pop();
            if (base.endsWith('.EXE') || base.endsWith('.386')) continue;
            if (existingMap && existingMap[e.path] && existingMap[e.path].byteLength >= e.size) {
                continue;
            }
            if (onProgress) {
                onProgress('Entpacke CD-Abbild: ' + e.path + ' (' + (e.size / (1024 * 1024)).toFixed(1) + ' MB)…');
            }
            extracted[e.path] = await readIsoBytes(e.lba, e.size);
        }
        return extracted;
    }

    async function checkSavedGameData() {
        var db = await openDB();
        return new Promise(function(resolve) {
            var tx = db.transaction(STORE_NAME, 'readonly');
            var store = tx.objectStore(STORE_NAME);
            var req = store.get(META_KEY);
            req.onsuccess = function() {
                db.close();
                var meta = req.result || null;
                resolve(meta);
            };
            req.onerror = function() {
                db.close();
                resolve(null);
            };
        });
    }

    // Exakte 65-Byte-Signatur der am 17.11. durch den Zwischenbau beschädigten RIVA.CFG
    // (MD5 7f27f35c4d35a2269dfe8300d523d4c4). Nur exakt diese Datei wird auf Byte 3 = 0x01
    // (GOG-Originalwert MD5 1636e1bd5a07d2cfebb5e6d7fbfb0047) korrigiert; jede andere
    // RIVA.CFG mit Sounds=0 (echte Spielereinstellung) bleibt unverändert.
    var KAPUTTE_RIVA_CFG_1711 = [
        0x15, 0x00, 0x01, 0x00, 0x64, 0x00, 0x00, 0x01, 0x50, 0x40, 0x01, 0x01, 0x02, 0x01, 0x00, 0x01,
        0x01, 0x01, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05,
        0x00, 0x06, 0x00, 0x07, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x0b, 0x00, 0x0c, 0x00, 0x0d,
        0x00, 0x0e, 0x00, 0x0f, 0x00, 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15,
        0x00
    ];

    function sanitizeImportedRivaCfg(pathKey, u8) {
        if (!u8 || !(u8 instanceof Uint8Array)) return u8;
        if ((pathKey === 'DATA/RIVA.CFG' || pathKey === 'RIVA.CFG') &&
            u8.byteLength === KAPUTTE_RIVA_CFG_1711.length) {
            for (var i = 0; i < KAPUTTE_RIVA_CFG_1711.length; i++) {
                if (u8[i] !== KAPUTTE_RIVA_CFG_1711[i]) return u8;
            }
            var copy = new Uint8Array(u8.byteLength);
            copy.set(u8);
            copy[3] = 0x01;
            return copy;
        }
        return u8;
    }

    async function loadSavedGameFiles(onProgress) {
        var db = await openDB();
        var rawItems = await new Promise(function(resolve, reject) {
            var tx = db.transaction(STORE_NAME, 'readonly');
            var store = tx.objectStore(STORE_NAME);
            var items = [];
            var count = 0;
            var cursorReq = store.openCursor();
            cursorReq.onsuccess = function(ev) {
                var cursor = ev.target.result;
                if (cursor) {
                    if (cursor.key !== META_KEY) {
                        items.push({ key: cursor.key, val: cursor.value });
                        count++;
                        if (onProgress && count % 10 === 0) {
                            onProgress('Lade Spieldaten aus Browser-Speicher (' + count + ' Dateien)…');
                        }
                    }
                    cursor.continue();
                } else {
                    db.close();
                    resolve(items);
                }
            };
            cursorReq.onerror = function(ev) {
                db.close();
                reject(ev.target.error || new Error('Fehler beim Lesen aus IndexedDB.'));
            };
        });
        var files = {};
        for (var i = 0; i < rawItems.length; i++) {
            var k = rawItems[i].key;
            var v = rawItems[i].val;
            var u8;
            if (v instanceof Blob) {
                u8 = new Uint8Array(await v.arrayBuffer());
            } else if (v instanceof Uint8Array) {
                u8 = v;
            } else {
                u8 = new Uint8Array(v);
            }
            files[k] = sanitizeImportedRivaCfg(k, u8);
        }
        return files;
    }

    async function clearSavedGameData() {
        var db = await openDB();
        await new Promise(function(resolve, reject) {
            var tx = db.transaction(STORE_NAME, 'readwrite');
            tx.objectStore(STORE_NAME).clear();
            tx.oncomplete = function() { db.close(); resolve(); };
            tx.onerror = function(ev) { db.close(); reject(ev.target.error); };
        });
    }

    async function validateAndStoreFiles(rawFileMap, onProgress) {
        var keys = Object.keys(rawFileMap);
        var hasRivaAlf = !!rawFileMap['DATA/RIVA.ALF'] || !!rawFileMap['RIVA.ALF'];
        if (!rawFileMap['DATA/RIVA.ALF'] && rawFileMap['RIVA.ALF']) {
            rawFileMap['DATA/RIVA.ALF'] = rawFileMap['RIVA.ALF'];
            delete rawFileMap['RIVA.ALF'];
            hasRivaAlf = true;
        }
        var hasRivaExe = !!rawFileMap['RIVA.EXE'];
        var hasEnglishRiva = !!(rawFileMap['ARKANIA3.EXE'] || rawFileMap['SHADOWS.EXE'] || rawFileMap['ROA3.EXE']);
        var hasDsa1 = !!(rawFileMap['SCHICKM.EXE'] || rawFileMap['BLADE.EXE'] || rawFileMap['SCHICK.DAT'] || rawFileMap['DATA/SCHICK.DAT']);
        var hasDsa2 = !!(rawFileMap['SCHWEIF.EXE'] || rawFileMap['TRAIL.EXE'] || rawFileMap['STARTRAI.EXE'] || rawFileMap['STARTRAIL.EXE'] || rawFileMap['DATA/STAR.DAT']);

        if (hasDsa1 && !hasRivaAlf) {
            throw new Error(
                'DSA 1 (Die Schicksalsklinge) erkannt. Bitte wähle das Spielverzeichnis von DSA 3: Schatten über Riva (mit RIVA.EXE und DATA\\RIVA.ALF).'
            );
        }
        if (hasDsa2 && !hasRivaAlf) {
            throw new Error(
                'DSA 2 (Sternenschweif) erkannt. Bitte wähle das Spielverzeichnis von DSA 3: Schatten über Riva (mit RIVA.EXE und DATA\\RIVA.ALF).'
            );
        }
        if (hasEnglishRiva) {
            throw new Error(
                'Englische Version (Shadows over Riva) erkannt. Dieser Port unterstützt ausschließlich die deutsche CD-Version V1.12 von DSA 3: Schatten über Riva (RIVA.EXE, 2.477.899 Bytes).'
            );
        }

        var missing = [];
        for (var i = 0; i < PFLICHT_DATEIEN.length; i++) {
            if (!rawFileMap[PFLICHT_DATEIEN[i]]) {
                missing.push(PFLICHT_DATEIEN[i]);
            }
        }
        if (missing.length > 0) {
            throw new Error(
                'Pflichtdateien fehlen: ' + missing.join(', ') +
                '. Bitte wähle deinen vollständigen Schatten-über-Riva-Ordner (deutsche GOG-Installation „Realms of Arkania 3“ oder Original-CD mit RIVA.EXE und DATA\\RIVA.ALF).'
            );
        }

        var exeBytes = rawFileMap['RIVA.EXE'];
        var exeHash = await sha256Hex(exeBytes);
        if (exeBytes.byteLength !== SOLL_RIVA_EXE_GROESSE && !BEKANNTE_VERSIONEN[exeHash]) {
            throw new Error(
                'Nicht unterstützte RIVA.EXE erkannt (' + exeBytes.byteLength.toLocaleString('de-DE') + ' Bytes). ' +
                'Erwartet wird die deutsche CD-Version V1.12 von DSA 3: Schatten über Riva (RIVA.EXE mit 2.477.899 Bytes, keine englische Fassung).'
            );
        }

        var versionLabel = BEKANNTE_VERSIONEN[exeHash] || ('DSA 3: Schatten über Riva – Deutsche CD-Version V1.12 (RIVA.EXE, ' + exeBytes.byteLength.toLocaleString('de-DE') + ' Bytes)');
        var unknownVersionWarning = !BEKANNTE_VERSIONEN[exeHash] && exeBytes.byteLength !== SOLL_RIVA_EXE_GROESSE;

        var musicTracks = 0;
        var totalBytes = 0;
        keys = Object.keys(rawFileMap);
        for (var k = 0; k < keys.length; k++) {
            if (/^MUSIC\/TRACK\d+\.OGG$/i.test(keys[k])) musicTracks++;
            totalBytes += rawFileMap[keys[k]].byteLength;
        }

        var hasCdSeqs = !!(rawFileMap['DATA/SEQS.ALF'] && rawFileMap['DATA/SPEX.ALF']);
        var hasFullSpeech = !!(rawFileMap['DATA/RAW1.ALF'] && rawFileMap['DATA/SPEX.ALF']);

        if (onProgress) onProgress('Speichere ' + keys.length + ' Dateien in IndexedDB…');

        var meta = {
            importedAt: new Date().toISOString(),
            fileCount: keys.length,
            totalBytes: totalBytes,
            musicTracks: musicTracks,
            hasCdData: hasCdSeqs,
            hasFullCdSpeech: hasFullSpeech,
            exeSha256: exeHash,
            versionLabel: versionLabel,
            unknownVersionWarning: unknownVersionWarning
        };

        var db = await openDB();
        await new Promise(function(resolve, reject) {
            var tx = db.transaction(STORE_NAME, 'readwrite');
            var store = tx.objectStore(STORE_NAME);
            store.clear();
            store.put(meta, META_KEY);
            for (var m = 0; m < keys.length; m++) {
                var p = keys[m];
                rawFileMap[p] = sanitizeImportedRivaCfg(p, rawFileMap[p]);
                var valToStore = (typeof Blob !== 'undefined') ? new Blob([rawFileMap[p]]) : rawFileMap[p];
                store.put(valToStore, p);
            }
            tx.oncomplete = function() { db.close(); resolve(); };
            tx.onerror = function(ev) { db.close(); reject(ev.target.error || new Error('Fehler beim Speichern in IndexedDB.')); };
        });

        return { meta: meta, files: rawFileMap };
    }

    async function importFromFileList(fileList, onProgress) {
        var rawFileMap = {};
        var arr = Array.from(fileList || []);
        if (arr.length === 0) {
            throw new Error('Keine Dateien ausgewählt.');
        }

        if (arr.length === 1 && arr[0].name.toLowerCase().endsWith('.zip')) {
            return await importFromZipFile(arr[0], onProgress);
        }

        var gogIsoFiles = [];
        for (var i = 0; i < arr.length; i++) {
            var f = arr[i];
            var rel = f.webkitRelativePath || f.fullPath || f.name;
            var norm = normalizeGameRelPath(rel);
            if (!shouldImportFile(norm)) continue;
            if (norm === 'GAME.GOG') {
                gogIsoFiles.push(f);
                continue;
            }
            if (onProgress && i % 5 === 0) {
                onProgress('Lese Datei ' + (i + 1) + ' / ' + arr.length + ' (' + norm + ')…');
            }
            var buf = await f.arrayBuffer();
            rawFileMap[norm] = new Uint8Array(buf);
        }

        for (var g = 0; g < gogIsoFiles.length; g++) {
            var isoExtracted = await extractFromGogIsoBlob(gogIsoFiles[g], rawFileMap, onProgress);
            var isoKeys = Object.keys(isoExtracted);
            for (var ik = 0; ik < isoKeys.length; ik++) {
                rawFileMap[isoKeys[ik]] = isoExtracted[isoKeys[ik]];
            }
        }

        return await validateAndStoreFiles(rawFileMap, onProgress);
    }

    async function importFromZipFile(zipFile, onProgress) {
        if (typeof fflate === 'undefined') {
            throw new Error('ZIP-Bibliothek (fflate) nicht geladen.');
        }
        if (onProgress) onProgress('Lese ZIP-Archiv (' + (zipFile.size / (1024 * 1024)).toFixed(1) + ' MB)…');
        var ab = await zipFile.arrayBuffer();
        if (onProgress) onProgress('Entpacke ZIP-Archiv…');
        var unzipped = fflate.unzipSync(new Uint8Array(ab));
        var rawFileMap = {};
        var gogBlobs = [];
        var entryNames = Object.keys(unzipped);
        for (var i = 0; i < entryNames.length; i++) {
            var entry = entryNames[i];
            if (entry.endsWith('/')) continue;
            var data = unzipped[entry];
            if (!data || data.byteLength === 0) continue;
            var norm = normalizeGameRelPath(entry);
            if (!shouldImportFile(norm)) continue;
            if (norm === 'GAME.GOG') {
                gogBlobs.push(new Blob([data]));
                continue;
            }
            rawFileMap[norm] = data;
        }
        for (var g = 0; g < gogBlobs.length; g++) {
            var isoExtracted = await extractFromGogIsoBlob(gogBlobs[g], rawFileMap, onProgress);
            var isoKeys = Object.keys(isoExtracted);
            for (var ik = 0; ik < isoKeys.length; ik++) {
                rawFileMap[isoKeys[ik]] = isoExtracted[isoKeys[ik]];
            }
        }
        return await validateAndStoreFiles(rawFileMap, onProgress);
    }

    window.DSADaten = {
        checkSavedGameData: checkSavedGameData,
        loadSavedGameFiles: loadSavedGameFiles,
        clearSavedGameData: clearSavedGameData,
        validateAndStoreFiles: validateAndStoreFiles,
        importFromFileList: importFromFileList,
        importFromZipFile: importFromZipFile,
        extractFromGogIsoBlob: extractFromGogIsoBlob
    };
})();
