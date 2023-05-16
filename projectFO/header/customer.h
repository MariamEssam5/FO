#include <iostream>
#include "varlen.h"
using namespace std;
class customer {
public:char name[31];
	  int phoneNum;
	  char address[30];
	  customer();
	  customer(short num, char namee[],char add[]);

	  void InitRecord(VariableLengthRecord&); //set Record  Configuration

	  int Pack(VariableLengthRecord&);	//  From ObjectPerson  to  Record =>  Write


	  int Unpack(VariableLengthRecord&);  // From Record to  Object Person  => Read


	  void Print(ostream&);

};