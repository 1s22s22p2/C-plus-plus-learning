#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

void PrintEntity(Entity* e);
void PrintEntity(const Entity& e);

class Entity
{
public:
	int x, y;

	/*Entity(int x, int y)
		:x(x), y(y) {}*/
	Entity(int x, int y)
	{
		/*Entity* e = this;
		e->x = x, e->y = y;*/
		/*this->x = x, this->y = y;*/
		(*this).x = x, (*this).y = y;

		PrintEntity(this);    //用这个来调用类外函数时将类参数输入
		PrintEntity(*this);    //解引用
		delete this;         //this的离谱用法
	} //this在非const函数中是Entity*，在const函数中是const Entity*

};

void PrintEntity(Entity* e)
{
	//print something
}

void PrintEntity(const Entity& e)
{
	//print something
}

int main()
{

	std::cin.get();
}