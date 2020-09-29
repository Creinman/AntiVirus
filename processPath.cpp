if(argc 0){
// - Создание коллекции
AVRCollection = new SAVRecordCollection(hAVBFile.getRecordCount());
for(DWORD RecID = 0; RecID RecordCount; RecID++){
if(!hAVBFile.readNextRecord(&AVRCollection->Record[RecID])){
cout << "> Error loading record #" << RecID << endl;
}
}
hAVBFile.close();
}else{
hAVBFile.close();
cout << "> Empty AV Base. Stop." << endl;
return 0;
}
cout << "t" << AVRCollection->RecordCount << " records loaded." << endl;

// 
cout << endl;
cout << "Starting scan for viruses" << endl;
cout << endl;

processPath(SrcPath);
//****************************************************
void processPath(PCSTR Path){
string SrcPath = Path;
string File;
File = Path;
File += "*.*";

WIN32_FIND_DATAA FindData; 
HANDLE hFind = FindFirstFileA(File.c_str(), &FindData);

do{
// - Пропускаем папки . и ..
if(!strcmp(FindData.cFileName, ".") || !strcmp(FindData.cFileName, "..")) continue;

File = Path;
File += "";
File += FindData.cFileName;

// - Если папка, то сканируем рекурсивно
if((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
processPath(File.c_str());
// - Иначе проверяем на вирусы
}else{
checkFile(File.c_str());
}

} while(FindNextFileA(hFind, &FindData));


}
