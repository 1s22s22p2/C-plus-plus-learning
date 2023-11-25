#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

class Entity
{
public:
	float x, y;

	void Move(float xa, float ya)
	{
		x += xa;
		y += ya;
	}

	Entity()
	{
		x = 0.0f, y = 0.0f;
	}                                  //这里的构造函数在继承后也可以调用，但是不能初始化派生类独有的变量
};

//class Palyer
//{
//public:
//	const char* Name;
//	float x, y;
//
//	void Move(float xa, float ya)
//	{
//		x += xa;
//		y += ya;
//	}
//
//	void PrintName()
//	{
//		std::cout << Name << std::endl;
//	}
//};

class Player:public Entity             //Player类既是Player类也是Entity类，它拥有Entity的一切public中的  //继承多个类用，连接
{
public:
	const char* Name;
	
	void PrintName()
	{
		std::cout << Name << std::endl;
	}
};                          //与上面注释的一个含义

int main()
{
	Player player;
	std::cout << player.x<< std::endl;
	std::cin.get();
}