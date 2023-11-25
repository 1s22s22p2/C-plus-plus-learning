#include <iostream>

#define Log(x) std::cout<<x<<std::endl;

int main()
{
	void* ptr = nullptr;           //0 is not a vaild address.#define NULL 0,the same is nullptr
	int var = 8;
	void* ptr1 = &var;             //& can tell us the address of var
	int* ptr2 = &var;              //the type have no influence on pointer
	double* ptr3 = (double*)&var;  //we can change the type in this way,and the type of var don't change
	*ptr2 = 10;                    //however the type make sense while dereference,we can't write *ptr1=10 because of the type
	*ptr3 = 10;                    //double pointer can't used in int too£¬because double 10 is 00 00 00 00 00 00 24 40,which is 0 in int
	char* buffer = new char[8];    //distribute a memory which is 8 bytes and returns a address where the memory starts
	memset(buffer, 0, 8);          //to input the memory with 0 in 8 bytes
	delete[] buffer;
	char** ptr4 = &buffer;            //double pointers or tripe pointers is also allowed
	std::cin.get();
	delete ptr;
	ptr = NULL;                    //when we don't need the pointer,we should delete the pointer and make it null
}