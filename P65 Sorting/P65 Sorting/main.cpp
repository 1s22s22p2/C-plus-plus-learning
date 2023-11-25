#include <iostream>
#include <vector>
#include <algorithm>     //这里面包含std::sort
#include <functional>

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	std::vector<int> values = { 3,5,1,4,2 };
	std::sort(values.begin(), values.end());  //这会使它默认升序排序

	for (int value : values)
	{
		std::cout << value << std::endl;
	}

	std::sort(values.begin(), values.end(), std::greater<int>());          //也可以传入函数指针
	for (int value : values)
	{
		std::cout << value << std::endl;
	}

	std::sort(values.begin(), values.end(), [](int a, int b) {return a < b; });   //在sort中比较函数会返回true或者flase如果为true那么前一个数字排在前面，如果为flase后一个排前面


	std::cin.get();
}