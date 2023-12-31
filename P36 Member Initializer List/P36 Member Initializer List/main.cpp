#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

class example
{
public:
	example()
	{
		std::cout << "you create a example!" << std::endl;
	}
	example(int x)
	{
		std::cout << "you create a example as " << x << std::endl;
	}
};

class Entity
{
private:
	std::string m_Name;
	int m_Score;
	example m_example;
public:
	//Entity()
	//{
	//	m_Name = "Unknown";   //在这里m_Name实际上被构造了两次。性能浪费，但是对于整形这种基本类型（不是字符串这种类）它不会被初始化，知道显式赋值才会初始化他们
	//	m_example=example(8);
	//}
	//Entity(const std::string& name)     //在新建对象时运行了一次，在赋值时运行一次
	//{
	//	m_Name = name;
	//}
	const std::string& GetName() const { return m_Name; }
	/*上面两个可以用下面的来代替*/
	Entity()
		:m_Name("unknown"), m_Score(0),m_example(example(8))   //这里只有最初新建时赋值了
	{
	}
	Entity(const std::string& name)
		:m_Name(name),m_Score(0)       //要按申明成员列表相同的顺序写，否则会引来依赖问题
	{
	}
};

int main()
{
	Entity e;
	std::cout << e.GetName() << std::endl;
	Entity e1("Cherno");
	std::cout << e1.GetName() << std::endl;

	std::cin.get();
	
}