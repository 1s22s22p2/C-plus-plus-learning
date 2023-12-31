#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	int* array = new int[50];

	int** a2d = new int* [50];           //分配50个int*来储存50个int指针，我们存储的实际数组还没有被分配，只有两百个字节的内存

	for (int i = 0; i < 50; i++)
	{
		a2d[i] = new int[50];           //在其他地方存储了这50个变量，我们可以通过访问二维数组获得指针，在依靠这些指针访问其内部
	}

	//int*** a3d = new int** [50];
	//for (int i = 0; i < 50; i++)
	//{
	//	a3d[i] = new int* [50];
	//	for (int j = 0; j < 50; j++)
	//	{
	//		a3d[i][j] = new int[50];
	//	}
	//}                                 //三维就是这样

	/*delete[][] a2d;*/
	//delete[] a2d;      //不可以因为这样只释放了指针的数组所占用的空间，而指针分身所指向的那一部分空间没有释放
	for (int i = 0; i < 50; i++)
	{
		delete[] a2d[i];
	}
	delete[] a2d;

	//多维数组很明显会导致内存碎片的问题，会使我们浪费时间从ram中获取数据，会慢很多
	//如果要存储一个5*5的二维数组，不如存储一个25的一维数组

	std::cin.get();
}