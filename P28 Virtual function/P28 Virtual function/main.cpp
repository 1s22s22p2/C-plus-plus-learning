#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

class Entity
{
public:
	//加上virtual即意味着这个函数是虚函数
	virtual std::string GetName()            //std::string因为string是定义在std命名空间里的类
	{
		return "Entity";
	}
};

class Player :public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name):m_Name(name) {}
	std::string GetName() override { return m_Name; }	//override表示这是被重写的函数,可以不写，但是为了可读性最好写上
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;      //对Entity对象使用是正常的，但是对于Player对象用调用的却是Entity中的getname
}

int main()
{
	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;
	PrintName(e);

	Player* p = new Player("Cherno");
	std::cout << p->GetName() << std::endl;
	PrintName(p);

	Entity* entity = p;
	std::cout << entity->GetName() << std::endl;

	std::cin.get();
}
//运行虚函数是有代价的，一方面要用内存来存储虚表，一方面调用函数时我们要遍历虚表，额外性能损失