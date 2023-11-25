#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

class Entity
{
	int x, y;
protected:
	int a, b;
public:
	Entity()
	{
		x = 0, y = 0;
		a = 0, b = 0;
	}
};

class Player :public Entity
{
public:
	Player()
	{
		/*x = 0, y = 0;*/                    //只有Entity以及它的友元可以访问x,y
		a = 0, b = 0;
	}
};

int main()
{
	Entity e;
	/*e.x = 0;*/                           //无法访问
	/*e.a=0,e.b=0*/                        //无法访问
	std::cin.get();
}