#include <string.h>
#include "customer.h"
customer::customer() {
	name[0] = 0;
	phoneNum = 0;
	address[0] = 0;
}
customer::customer(short num, char namee[], char add[])
{
	phoneNum = num;
	strcpy_s(name, namee);
	strcpy_s(address, add);


}
void customer::InitRecord(VariableLengthRecord& record)
{
	record.init(3);
	record.AddField(0, 'D', '|');
	record.AddField(1, 'F', 2);  // Fixed :  F , Length Indicator : L , Delimited  D
	record.AddField(2, 'D', '|');


}

int customer::Pack(VariableLengthRecord& record)
{
	// pack the fields into a VariableLengthRecord, return  ( 1 )TRUE if all succeed, FALSE o/w
	int result, recordSize = 0;   // Lenght Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	recordSize = 2 + strlen(address) + strlen(name) + 1;

	record.Clear(recordSize);

	result = record.Pack(0, (void*)&phoneNum, sizeof(short));
	result = result && record.Pack(1, (void*)name, strlen(name));
	result = result && record.Pack(1, (void*)address, strlen(address));

	return result;
}

int customer::Unpack(VariableLengthRecord& record)
{
	int result;
	result = record.Unpack(0, (char*)&phoneNum);
	result = result && record.Unpack(1, name, true);
	result = result && record.Unpack(2, address);

	return result;
}

void customer::Print(ostream& stream)
{
	stream << "customer:"
		<< "\tName '" << name << "'\n"
		<< "\tPhone Number '" << phoneNum << "'\n"
		<< "\tAddress'" << address << "'\n";
}