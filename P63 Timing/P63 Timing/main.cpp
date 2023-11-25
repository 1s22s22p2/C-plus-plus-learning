#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << "Timer took" << duration.count()*1000.0f << 'ms' << std::endl;
	}
};

void Function()
{
	Timer timer;

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Hello" << std::endl;
	}
}

void Function1()
{
	Timer timer;

	for (int i = 0; i < 100; i++)
	{
		std::cout << "Hello\n";
	}
}

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	using namespace std::literals::chrono_literals;           //有了这个才可以用1s中的s   

	auto start = std::chrono::high_resolution_clock::now();   //这里返回值类型相当长所以选择用auto

	std::this_thread::sleep_for(1s);                          //1s左右不一定是准确的1s，因为首先线程的睡眠时间不能保证是我们告诉它的睡眠时间，而且计时本身也有时间花销
	
	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;
	std::cout << duration.count() << 's' << std::endl;
	//使用于所有平台所以非常推荐，除非在处理一些底层的问题

	std::thread function(Function);
	std::thread function1(Function1);

	Function();            //可以直接定义一个类，利用对象的生存期来计时，那样可以在实现计算函数时间的同时，缩减代码
	Function1();

	function.join();
	function1.join();

	std::cin.get();
}