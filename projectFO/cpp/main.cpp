#include<iostream>
#include<fstream>
#include<string>
#include"customer.h"
#include"product.h"
#include"staff.h"
using namespace std;
int main() {
	product productt;

	VariableLengthRecord outRecord, inRecord;

	strcpy_s(productt.name, "rice");
	productt.price = 40;
	productt.qty = 20;
	productt.InitRecord(outRecord);

	cout << "pack product " << productt.Pack(outRecord) << endl;


#pragma region Writing (Packing)



	ofstream TestOut("deltext.dat", ios::out | ios::binary);

	outRecord.WriteHeader(TestOut);  // Only Once.

	outRecord.Write(TestOut);
	productt.Print(cout);
	return 0;
}