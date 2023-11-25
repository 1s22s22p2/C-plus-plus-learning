#include <iostream>
#include <string>
#include <memory>          //要访问所有智能指针，首先要写这个

#define Log(x)	std::cout<<x<<std::endl;

class Entity
{
public:
	Entity()
	{
		std::cout << "Create Entity" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroy Entity" << std::endl;
	}

	void print() {}
};



int main()
{

	//unique_ptr
	{
		std::unique_ptr<Entity> entity;    //在std命名空间，有一个模板参数    
		//这个语句实际上并没有给entity任何空间，它只不过是一个指针
		//其中模板参数的作用是强调这个指针只能指向Entity类，但是它并没有实例化
		std::unique_ptr<Entity> entity1(new Entity);
		/*std::unique_ptr<Entity> entity1=new Entity();*/  //unique_ptr上标注了explicit,不能直接隐式调用构造函数
		std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();  //这个方法更好，因为如果构造函数碰巧抛出异常，我们也不会得到一个没有引用的悬空指针（造成内存泄露）  //异常安全
		/*std::unique_ptr<Entity> e = entity;  */                      //在这了里面拷贝构造函数和拷贝构造操作符，实际上被删除了
		entity = std::make_unique<Entity>();
		/*std::unique_ptr<Entity> entity6;
		entity6 = new Entity;
		std::unique_ptr<Entity> entity7;
		entity7 = entity1;
		std::unique_ptr<int> a;*/                   //如果构造了一个作用域指针但是不初始化，那么不能通过赋值初始化，只能通过entity = std::make_unique<Entity>();

		entity->print();
	}
	//Entity e;
	//Entity* entity3;       //正如这个指针实际上也没有实例化，所以也不调用构造函数
	//Entity* entity4 = &e;   //所以新建指针并不会调用构造函数，真正能够实例化类的只有new Entity 和其他实例化语句
	//Entity* entity5 = new Entity();

	//shared_ptr
	{
		std::weak_ptr<Entity> weakEntity;   //可以复制shared_ptr但是不会增加引用数
		{
			std::shared_ptr<Entity> e0;
			{
				std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
				/*	std::shared_ptr<Entity> sharedEntity2(new Entity);*/   //虽然可以运行但是不要用，
					//因为shared需要另外分配一个内存，叫做控制块，用来存储引用计数
					//如果我们首先创建了一个new Entity传给了shared_ptr,它必须分配，做两次内存分配，一次new ENtity的分配，还有shared_ptr的控制内存块的分配
					//所以前者更有效率
				e0 = sharedEntity;  //可以复制
				weakEntity = e0;   

			}
		}  //知道全都超出作用域才调用析构函数
	}      
	//可以让我们的内存管理自动化，share_ptr会有一点花销因为引用计数系统，尽量使用unique_ptr，因为它的花销更小


	std::cin.get();
}