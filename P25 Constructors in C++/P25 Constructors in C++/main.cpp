#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

class Entity
{
public:
	float x, y;

	/*Entity() = delete;*/       //C++自带了构造函数如果不想用可以delete

	Entity()
	{
		x = 0.0f;
		y = 0.0f;
		std::cout << "Created Entity！" << std::endl;
	}                 //在创造一个实例时自动运行，名字必须是Entity

	//Entity(float xx,float yy)      //可以有多个函数但是变量必须不同
	//{
	//	x = xx;
	//	y = yy;
	//}

	/*void Init()
	{
		x = 0.0f;
		y = 0.0f;
	}*/

	~Entity()                      //析构函数名字有~
	{
		std::cout << "Destroyed Entity！" << std::endl;
	}

	void Print()
	{
		std::cout << x << ',' << y << std::endl;
	}
};

void function()
{
	Entity e;
	e.Print();                   //如果在main里面定义e，那么在main执行完毕时自动调用析构函数，但是此时控制台已经关闭，所以用function观察析构函数
	/*e.~Entity();*/
}

int main()
{
	//Entity e;
	//Entity e1(10.0f, 5.0f);
	///*e.Init();*/
	//e.Print();
	//e1.Print();
	function();                  //在栈上的数据在函数结束时自动析构，而在堆上的（new的）要自己删除（delete）
	std::cin.get();
}