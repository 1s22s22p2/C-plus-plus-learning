#include <iostream>
#include <vector>
#include <algorithm>

#define Log(x)	std::cout<<x<<std::endl

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
	{
		func(value);
	}
}

int main()
{
	std::vector<int> values = { 1,5,4,2,3 };
	auto lambda = [](int values) {Log("Vlaue:" << values); };  
	auto it=std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });   //遍历整个vector返回>3的第一个数
	std::cout << *it << std::endl;

	//[a,&b]指a通过复制，b通过引用传递
	//[this]捕获当前对象进行传递
	//[&]捕获lambda函数体中用到的变量，引用传递
	//[=]捕获lambda函数体中用到的变量，作为拷贝传递
	//[]什么都不捕获                      //[]表明了我们打算如何传递变量
	ForEach(values, lambda);

	int a = 5;
	auto lambda1 = [a](int values)mutable {a = 5;  Log("Vlaue:" << a); };   //通过值传递的话，要修改传递的变量要加上mutable
	auto lambda1 = [&a](int values) {a = 5;  Log("Vlaue:" << a); };

	std::cin.get();
}