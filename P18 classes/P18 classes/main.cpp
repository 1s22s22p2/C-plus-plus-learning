#include <iostream>

#define Log(x) std::cout<<x<<std::endl;

class Player                //由类类型制成的变量叫做对象，新创建对象的过程叫做实例化,默认情况下类中的访问控制都是私有的，只有类内部函数可以访问这些变量
{
public:
	int x, y;
	int speed;
	void move(int xa, int ya)    //定义再类里面，不需要再传递类这个变量，其中的x,y,speed直接用所属类中的就可以
	{
		x += xa*speed;
		y += ya*speed;
	}
};                          //at the end we have a ";"

int main()
{
	Player player;           //实例化
	player.x = 5;
	Log(player.x);
	player.move(1, -1);
	std::cin.get();
}