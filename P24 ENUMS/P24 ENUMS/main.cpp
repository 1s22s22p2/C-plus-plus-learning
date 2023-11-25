#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

enum Exampe:unsigned char      //to point out the type of the data,we can't use float because it is not a integer
{
	A=5,B=7,C         //without ';',if we don't say what A,B,C is, it is believed to be 0,1,2.//    //C=B+1,
};

//int A = 0;
//int B = 1;
//int C = 2;

int main()
{
	Exampe value = B;         //make the value can only be A,B,C 

	if (value == B)
	{
		//Do something here
	}

	std::cin.get();
}