#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

using String = std::string;

class Entity
{
private:
	String m_name;
public:
	Entity()
		:m_name("Unknown") 
	{
		std::cout << "construct 1" << std::endl;
	}
	Entity(const String& name)         //const string可以引用字符串常量,string不可以,因为如果string想要引用就要改成（（string&）cherno）
		:m_name(name) 
	{
		std::cout << "construct 2" << std::endl;
	}
	const String& GetName() const
	{
		return m_name;
	}
};

int main()
{
	Entity* e;
	{
		//栈分配
		Entity entity;
		Entity entity1("cherno");
		Entity entity2 = Entity("cherno");   //这个语句也只调用一次构造函数
		e = &entity2;
		std::cout << entity2.GetName() << std::endl;

		//堆分配
		Entity* entity3 = new Entity("cherno");    //new Entity的意思是我们在堆上分配了内存，然后我们用Entity*创建了一个指针指向该内存
		e = entity3;                               //e=&entity也可以
		std::cout << (*entity3).GetName() << std::endl;
	/*	std::cout << entity3->GetName() << std::endl;*/
	
	}                                        //生存域不一定是函数，也可以是if语句，甚至空作用域
	/*delete entity; */   //这里定义的entity指针超过了它的作用域，所以销毁，但是它所指向的那部分内存依旧被占用
	delete e;             //如果忘记delete就会导致内存泄露

	//std::cin.get();
	//{
	//	int* x = new int;
	//}
	//delete x;
}

//如果对象非常大，或者想要显式地控制对象的生存周期，那么在堆上创建，否则在栈上，可以自动回收，也很快