#include <iostream>
#include "varlen.h"
using namespace std;
class staff {
public:char name[31];
	  char position[20];
	  int salary;
	  int id;
	  staff();
	  staff(short sal, char namee[], char pos[],short iddd);

	  void InitRecord(VariableLengthRecord&); //set Record  Configuration

	  int Pack(VariableLengthRecord&);	//  From ObjectPerson  to  Record =>  Write


	  int Unpack(VariableLengthRecord&);  // From Record to  Object Person  => Read


	  void Print(ostream&);

};