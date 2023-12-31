#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

int s_Variable = 10;       
//如果无static，可以写extern int s_Varable
//来获得外部文件中的变量,如果直接int s_Varable则会报下述错误，
//而不加int s_Variable，又会说找不到s_Variable变量，
//而如果有static，即使使用extern int s_Varable也找不到

void Function()            //因为另一个文件的function是static所以不报错
{

}

int main()
{
	Log(s_Variable);       //如果static.cpp中的的s_Variable不加static就会出现link错误，因为该变量已经在其他单元中定义过了
	std::cin.get();
}

//static的这种性质可以运用于头文件，如果难以理解那就按照class里面的private理解，
//static尽量多用，可以避免很多奇怪的bug，因为如果用全局变量会出现很多意想不到的的变化