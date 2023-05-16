#include <string.h>
#include "product.h"
product::product() {
	price = 0;
	qty = 0;
	name[0] = 0;
}
product::product(short pricee, short qtyy, char namee[])
{
	price = pricee;
	qty = qtyy;
	strcpy_s(name, namee);

}
void product::InitRecord(VariableLengthRecord& record)
{
	record.init(3);
	record.AddField(0, 'F', 2);  // Fixed :  F , Length Indicator : L , Delimited  D
	record.AddField(1, 'D', '|');	
	record.AddField(2, 'D', '|');


}

int product::Pack(VariableLengthRecord& record)
{
	// pack the fields into a VariableLengthRecord, return  ( 1 )TRUE if all succeed, FALSE o/w
	int result, recordSize = 0;   // Lenght Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	recordSize = 2 +2+ strlen(name) + 1;

	record.Clear(recordSize);

	result = record.Pack(0, (void*)&price, sizeof(short));
	result = result && record.Pack(1, (void*)&qty, sizeof(short));
	result = result && record.Pack(2, (void*)name, strlen(name));

	return result;
}

int product::Unpack(VariableLengthRecord& record)
{
	int result;
	result = record.Unpack(0, (char*)&price);
	result = result && record.Unpack(1, (char*)&qty);
	result = result && record.Unpack(2, name, true);
	return result;
}

void product::Print(ostream& stream)
{
	stream << "Product:"
		<< "\tPrice '" << price << "'\n"
		<< "\tName '" << name << "'\n";
}