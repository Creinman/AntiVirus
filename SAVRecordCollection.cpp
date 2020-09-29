#include 
#include 
#include 
#include 

#include 
#include 


using namespace std;

//! Коллекция записей
typedef struct SAVRecordCollection{
SAVRecordCollection(DWORD RecordCount){
this->RecordCount = RecordCount;
this->Record = new SAVRecord[this->RecordCount];
}
~SAVRecordCollection(){
[] this->Record;
}
DWORD RecordCount;
PSAVRecord Record;
} * PSAVRecordCollection;

// - Коллекция записей
PSAVRecordCollection AVRCollection = NULL;

void processPath(PCSTR Path);
void getMD5(const void* pData, size_t nDataSize, PDWORD RetHash);
