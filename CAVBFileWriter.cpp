// 
// - CAVBFileWriter
// 

//! Открытие файла
bool CAVBFileWriter::open(PCSTR FileName){
if(FileName == NULL) return false;
// - Если файл не найден то создаем его прототип
if(!isFileExist(FileName)){
hFile.open(FileName, ios::out | ios::binary);
if(!hFile.is_open()) return false;
hFile.write("AVB", 3); // - Сигнатура файла
hFile.write((PCSTR)&this->RecordCount, sizeof(DWORD)); // - Число записей
// - Иначе открываем и проверяем валидность
}else{
hFile.open(FileName, ios::in | ios::out | ios::binary);
if(!hFile.is_open()) return false;
// - Проверка сигнатуры
CHAR Sign[3];
hFile.read((PSTR)Sign, 3);
if(memcmp(Sign, "AVB", 3)){
hFile.close(); // - Это чужой файл
return false;
}
// - Читаем число записей
hFile.read((PSTR)&this->RecordCount, sizeof(DWORD));
}
return true;
}

bool CAVBFileWriter::addRecord(PSAVRecord Record){
if(Record == NULL || !hFile.is_open()) return false;
// - Перемещаемся в конец файла
hFile.seekp(0, ios::end);
// - Добавляем запись
hFile.write((PSTR)&Record->Signature.Offset, sizeof(DWORD)); // - Смещение сигнатуры
hFile.write((PSTR)&Record->Signature.Lenght, sizeof(DWORD)); // - Размер сигнатуры
hFile.write((PSTR)&Record->Signature.Hash, 4 * sizeof(DWORD)); // - Контрольная сумма
hFile.write((PSTR)&Record->NameLen, sizeof(BYTE)); // - Размер имени
hFile.write((PSTR)Record->Name, Record->NameLen); // - Имя
// - Смещаемся к числу записей
hFile.seekp(3, ios::beg);
// - Увеличиваем счётчик записей
this->RecordCount++;
hFile.write((PSTR)&this->RecordCount, sizeof(DWORD));

return true;
}
