// - Необходимые включения
#include 
#include 
#include 
#include 
#include 
#include 

using namespace std;


//! Копирование аргумента
bool copyArg(PCSTR Arg, DWORD Offset, PSTR Buffer, DWORD Size){
int ArgLen = strlen(Arg) - Offset;
if(ArgLen > Size - 1 || ArgLen Can't open source file. Stop." << endl;
return 0;
}
// - Чтение данных для расчёта контрольной суммы
PBYTE Buffer = new BYTE[Record.Signature.Lenght];
if(Buffer == NULL){
cout << "> Can't alloc memory for sign data. Stop." << endl;
hSrcFile.close();
return 0;
}
hSrcFile.seekg(Record.Signature.Offset, ios::beg);
hSrcFile.read((PSTR)Buffer, Record.Signature.Lenght);
// - Закрытие исходного файла
hSrcFile.close();
// - Расчёт хэша сигнатуры
getMD5(Buffer, Record.Signature.Lenght, Record.Signature.Hash);

// - Очистка буффера
Buffer;
