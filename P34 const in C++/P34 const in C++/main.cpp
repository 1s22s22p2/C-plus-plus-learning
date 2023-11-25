#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

class Entity
{
private:
	int m_X;
	int* m_Y;
	int m_Z;
	mutable int var;   //mutable意思是可变的，那么这个变量我们可以在const函数中修改
public:
	int GetX() const        //只有在类里面才能这么用,意思是这个方法不能修改实际的类，我们不能修改类的成员变量
	{
		/*m_X = 2;*/
		var = 3;
		return m_X;
	}
	int GetX()
	{
		return m_X;   //同名函数也可以通过const区分
	}
	void SetX(int x)
	{
		m_X = x;
	}
	const int* const GetY() const     //我们返回了一个不能修改的指针，指针的内容也不能修改，而且这个函数也承诺不会修改实际的Entity类
	{
		return m_Y;
	}
	int GetZ()
	{
		return m_Z;
	}
};
void PrintEntity(const Entity& e)
{
	std::cout << e.GetX() << std::endl;
	std::cout << e.GetY() << std::endl;
	/*std::cout << e.GetZ() << std::endl;*/        //这里GetZ（）不可以使用，因为我们承诺不更改Entity，但是我们调用了一个有可能改变Entity的函数
	//通过const Entity可以访问所有const函数，所以GetX（）调用的是const那个，而其他未注const则调用没有const的那个
}

int main()
{
	/*int a=5;
	a = 6;*/
	/*const int a=0;        //const在我们想要设置max，min时是很有意义的
	a = 5;*/

	/*const int MAX_AGE = 90;
	int* a = new int;
	*a = 2;
	a = (int*)&MAX_AGE;
	*a = 5;
	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl;
	int* A = (int*)&MAX_AGE;
	*A = 5;
	std::cout << *A << std::endl;
	std::cout << MAX_AGE << std::endl;*/


	//const int* b = new int;       //意思是我们不能修改指针所指向的内容了(a本身，即地址还是可以改变)
	////int const* 和const int* 意思一样
	///**b = 2;*/
	//b = (int*)&MAX_AGE;
	///**b = 5;*/ //即使所指的方向变量，新的内容也不可以改变

	int* const c = new int;       //意思是c本身不能改变，但是可以改变它指向的内容
	*c = 5;

	const int* const d = new int;  //两者都不能改变

	std::cin.get();

	//注意点
	const int MAX = 90;
	int* f = new int;
	*f= 2;
	f = (int*)&MAX;
	*f = 5;
	std::cout << *f << std::endl;
	std::cout << MAX << std::endl;   //这里const用的是针对int，char,float之类的不分配空间

	int i = 1;
	const int MAX_= i;
	int* e = new int;
	*e = 2;
	e = (int*)&MAX_;
	*e = 5;
	std::cout << *e << std::endl;
	std::cout << MAX_ << std::endl;  //用变量给const赋值分配空间
	//此外针对自定义数据类型（结构体或者类）分配空间
	//字符不分配空间但是字符串分配只读空间
}