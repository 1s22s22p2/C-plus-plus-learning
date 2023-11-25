#include <iostream>
#include <GLFW/glfw3.h>              //若要使用动态链接头文件不用改

//但是对于函数声明有很多不同之处

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	int a = glfwInit();
	Log(a);
	std::cin.get();
}