void checkFile(PCSTR FileName){
cout << FileName << "t";
// - Открываем файл
HANDLE hFile = CreateFileA(FileName, FILE_READ_ACCESS, NULL, NULL, OPEN_EXISTING, NULL, NULL);
if(hFile == INVALID_HANDLE_VALUE){
cout << "Error" << endl;
return;
}
// - Получаем размер файла
DWORD FileSize = GetFileSize(hFile, NULL);

// - Отображаем файл в память
HANDLE hMap = CreateFileMappingA(hFile, NULL, PAGE_READONLY, NULL, FileSize, NULL);
if(hFile == INVALID_HANDLE_VALUE){
cout << "Error" << endl;
CloseHandle(hFile);
return;
}
LPVOID File = MapViewOfFile(hMap, FILE_MAP_READ, NULL, NULL, FileSize);
if(File == NULL){
cout << "Error" << endl;
CloseHandle(hMap);
CloseHandle(hFile);
return;
}

// - Поиск по сигнатурам
bool Detected = false;
for(DWORD RecID = 0; RecID RecordCount; RecID++){
PSAVRecord Record = &AVRCollection->Record[RecID];
// - Если файл слишком маленький, то пропускам запись
if(FileSize Signature.Offset + Record->Signature.Lenght)) continue;
// - Переходим вычисляем контрольную сумму для сигнатуры
DWORD Hash[4];
getMD5((PBYTE)((DWORD)File + Record->Signature.Offset), Record->Signature.Lenght, Hash);

// - Детектим
if(!memcmp(Hash, Record->Signature.Hash, 4 * sizeof(DWORD))){
cout << " DETECTEDt" << Record->Name << endl;
Detected = true;
break;
}
}

UnmapViewOfFile(File);
CloseHandle(hMap);
CloseHandle(hFile);

if(!Detected) cout << "OK" << endl;
}
