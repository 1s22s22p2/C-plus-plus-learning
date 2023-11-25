#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

class Entity
{
public:
	////加上virtual即意味着这个函数是虚函数
	//virtual std::string GetName()            //std::string因为string是定义在std命名空间里的类
	//{
	//	return "Entity";                     //在基类的虚函数有实际的函数体，那么子类的重写函数可写可不写
	//}                                        //但有时候这个默认实现没有意义，实际上我们可能想强制子类为美国特定函数提供自己的定义
	virtual std::string GetName() = 0;       //virtual使它称为虚函数，0使它变成纯虚函数
};

class Player :public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name) :m_Name(name) {}
	std::string GetName() override { return m_Name; }	//override表示这是被重写的函数,可以不写，但是为了可读性最好写上   //这个函数必须定义因为基类里面有它的纯虚函数
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;      //对Entity对象使用是正常的，但是对于Player对象用调用的却是Entity中的getname
}

int main()
{
	/*Entity* e = new Entity();            //我们无法实例化一个纯虚函数
	std::cout << e->GetName() << std::endl;
	PrintName(e);*/

	Player* p = new Player("Cherno");      //我们只能实例化一个实现了所有纯虚函数的类
	std::cout << p->GetName() << std::endl;
	PrintName(p);

	Entity* entity = p;
	std::cout << entity->GetName() << std::endl;

	std::cin.get();
}