#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

struct Entity
{
	int x, y;
};

int main()
{
	int a = 50;
	double value = a;
	std::cout << value << std::endl;
	value = *(double*)&a;         //这个就是类型相关，将a的地址赋值double型的指针，然后在访问
	std::cout << value << std::endl;

	double& b = *(double*)&a;

	Entity e = { 5,8 };
	int* position = (int*)&e;

	std::cout << position[0] << ',' << position[1] << std::endl;      //通过这种方式将它转化为数组

	int y = *(int*)((char*)&e + 4);
	std::cout << y << std::endl;

	std::cin.get();
} 