#include <iostream>
//#include "GLFW/glfw3.h"   
//<>与""本质上没有区别，如果是引号的话会检查相对路径，如果没有找到任何相对于main.cpp的文件，它就会检查编译器的include路径
//所以如果源文件是在解决方案的某个地方就用就用""，如果它是一个完整的外部依赖，或者外部的库，不在visual studio中和我们的解决方案一起编译，那么就用<>,来表示它是外部的
extern "C" int glfwInit();     //想要调用这个函数也可以直接在这里声明，但是要写上extern "C",因为GLWF是一个C语言库 
 
#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	int a = glfwInit();
	Log(a);
	std::cin.get();
}

//头文件为我们提供了声明，告诉我们有那些函数可以用，库文件，提供了函数的定义，这样我们可以链接到那些函数