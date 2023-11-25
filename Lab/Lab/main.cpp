#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	int a = 5;
	int* ptr1 = &a;
	int* ptr2 = &a;
	Log(a);
	Log(*ptr1);
	Log(*ptr2);

	a = 6;
	Log("when a=6\n")
	Log(a);
	Log(*ptr1);
	Log(*ptr2);
	
	*ptr1 = 7;
	Log("when *ptr1=7\n");
	Log(a);
	Log(*ptr1);
	Log(*ptr2);

	*ptr2 = 8;
	Log("when *ptr2=8\n")
	Log(a);
	Log(*ptr1);
	Log(*ptr2);

	std::cin.get();
}