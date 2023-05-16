#include <string.h>
#include "staff.h"
staff::staff() {
	name[0] = 0;
	position[0] = 0;
	salary = 0;
	id = 0;
}
staff::staff(short sal, char namee[], char pos[], short idd) {
	salary = sal;
	strcpy_s(name, namee);
	strcpy_s(position, pos);	
		id = idd;
}
void staff::InitRecord(VariableLengthRecord& record)
{
	record.init(4);
	record.AddField(0, 'D', '|');
	record.AddField(1, 'F', 2);  // Fixed :  F , Length Indicator : L , Delimited  D
	record.AddField(2, 'D', '|');
	record.AddField(3, 'F', 2);
}
int staff::Pack(VariableLengthRecord& record)
{
	// pack the fields into a VariableLengthRecord, return  ( 1 )TRUE if all succeed, FALSE o/w
	int result, recordSize = 0;   // Lenght Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	recordSize = 2 + 2 + strlen(name) +strlen(position) + 1;

	record.Clear(recordSize);

	result = record.Pack(0, (void*)&salary, sizeof(short));
	result = result && record.Pack(1, (void*)&id, sizeof(short));
	result = result && record.Pack(2, (void*)position, strlen(position));
	result = result && record.Pack(3, (void*)name, strlen(name));

	return result;
}
int staff::Unpack(VariableLengthRecord& record)
{
	int result;
	result = record.Unpack(0, (char*)&salary);
	result = result && record.Unpack(1, (char*)&id);
	result = result && record.Unpack(2, name);
	result = result && record.Unpack(3, position, true);

	return result;
}

void staff::Print(ostream& stream)
{
	stream << "Staff:"
		<< "\tID '" << id << "'\n"
		<< "\tName '" << name << "'\n"
		<< "\tPosition '" << position << "'\n"
		<< "\tSalary '" << salary << "'\n";
}