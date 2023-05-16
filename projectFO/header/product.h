#include <iostream>
#include "varlen.h"
using namespace std;
class product {
public:char name[31]; 
	  int price;  
	  int qty;  
	  product();
	  product(short pricee,short qtyy, char namee[]);

	  void InitRecord(VariableLengthRecord&); //set Record  Configuration

	  int Pack(VariableLengthRecord&);	//  From ObjectPerson  to  Record =>  Write


	  int Unpack(VariableLengthRecord&);  // From Record to  Object Person  => Read


	  void Print(ostream&);

};