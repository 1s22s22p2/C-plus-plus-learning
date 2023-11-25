#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

struct Vector3
{
	float x, y, z;
public:
	Vector3()
		:x(10), y(11), z(12) {}
};

int main()
{
	//在栈上分配整数
	{
		int svalue = 5;
		int sarray[5];
		sarray[0] = 1;
		sarray[1] = 2;
		sarray[2] = 3;
		sarray[3] = 4;
		sarray[4] = 5;
		Vector3 svector;
	}
	//svalue和sarray在内存上紧挨着,依靠栈指针的移动而且栈往往时倒着来的，所以先声明的变量内存地址比较大
	//我们分配空间时，做的就是移动栈指针，然后返回栈指针的地址，所以快
	//当超出作用域时这一部分内存就会被弹出，因为栈指针移动到了原来的位置

	//在堆上分配整数
	int* hvalue = new int();
	*hvalue = 5;
	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	Vector3* hvector = new Vector3;
	//new实际上调用了一个一个叫做malloc的函数（memory allocate的缩写），这样做通常会调用底层操作系统或平台的特定函数为我们在堆上分配内存
	//特定函数：当我们启动程序时我们会得到一定数量的物理ram，分配给我们，我们的程序会维护一种叫做空闲列表（free list）的东西，它是跟踪哪些内存块是空闲的，
	//当我们使用malloc时它可以浏览空闲列表，然后找到一个空闲的内存，至少和我们要的一样大，然后我们自己赋一个指针，之后我们要记录分配的大小
	//如果使用堆可能会是一堆cache miss，而在栈中不可能得到这种报错

	std::cin.get();
}

//如果可能的话尽量在栈上分配，除非需要更长的作用域，或者太大的数据