// -
// - Добавление сигнатуры
cout << "Record info:" << endl;
printf( " Name: %sn", Record.Name);
printf( " Offset: 0x%x (%d)n", Record.Signature.Offset, Record.Signature.Offset);
printf( " Lenght: 0x%x (%d)n", Record.Signature.Lenght, Record.Signature.Lenght);
printf( " CheckSumm: 0x%x%x%x%xn", Record.Signature.Hash[0], Record.Signature.Hash[1], Record.Signature.Hash[2], Record.Signature.Hash[3]);
CAVBFileWriter hAVBFile;
hAVBFile.open(DstFile);
if(!hAVBFile.is_open()){
cout << "> Can't open database file. Stop." << endl;
return 0;
}
hAVBFile.addRecord(&Record);
hAVBFile.close();

cout << "Record added." << endl;

return 0;
