#include <iostream>
#include <array>

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	int example[5];         //意思是数组中的数据类型为整型
	example[0] = 2;         //数组从example[0]开始，0，1，2，3，4，没有5
	example[4] = 4;         //数组的数据在内存上是连续的他们把数据放在了一行

	/*example[-1] = 5;
	example[5] = 2;  */      //内存访问冲突（memory access violation）

	for (int i = 0; i < 5; i++)
		example[i] = i;         //数组总是与for循环一起使用  

	std::cout << example[0] << std::endl;
	std::cout << example << std::endl;         //只会打印出它的地址，因为它实际是个指针
	std::cout << *(example + 1) << std::endl;  //想要访问example[1]可以用example的地址加上一个元素的大小（4）
	int* ptr = example;
	std::cout << *(ptr + 1) << std::endl;      //指针加2的意思是我们要往后访问2个元素，指针会根据实际数据类型计算实际的字节数
	std::cout << *(int*)((char*)ptr + 1) << std::endl;    //如果真的想一个字节一个字节地处理可以这样 
	std::cin.get();

	//创建数组的两种方式
	int a[5];                      //在栈上创建一旦跳出作用域就自动销毁
	int count = sizeof(a) / sizeof(int);           //计算数组元素数量，虽然它没有考虑如果我们定义了一个a[-1]，而且只能计算栈上的数组大小
	int* another = new int[5];     //在堆上创建，会一直存活，直到我们把它销毁或者程序结束  
	for (int i = 0; i < 5; i++)
	{
		another[i] = i;
	}
	std::cout << *another << std::endl;        //实际上是间接寻址，如果访问another的地址得到的仍然是地址，然后再访问这个地址才是数据
	std::cout << *((int*)*another) << std::endl;      //由于内存之间跳跃所以再堆上创造指针会影响性能
	int count = sizeof(another) / sizeof(int);        //算出来是1,因为整型指针大小为1
	delete[] another;              //如果你想要返回的是函数内新创建的数组，那么就用new关键字

	//维护数组大小的正确方法
	const int Asize = 5;  //最好写成static const int size=5或者static constexpr int size =5
	int A[Asize];         //A中的size应该是常量
	for (int i = 0; i < Asize; i++)     //然后把它应用于for循环
		A[i] = i;

	//c++的std库里面还有原生的array数组std::array,它有边界检查，有记录数据大小的功能 ,虽然它有额外的花销但是值得的
	std::array<int, 5> other;   //如果想使用要再前面加#include <array>
	for (int i = 0; i < other.size(); i++)     //然后把它应用于for循环
		A[i] = i;

	//std::array更安全，但是还是推荐原生的数组，自行定义

}