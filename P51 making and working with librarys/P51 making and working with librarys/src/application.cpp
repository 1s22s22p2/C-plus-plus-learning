/*#include "../../Engine/src/Engine.h" */        //改名就会失效
#include <Engine.h>                            //因为我们把它指定为编译器的包含目录，我们可以将引号换成尖括号

#include <iostream>

int main()
{
	 engine::PrintMessage();
}
//要在项目P51……项目上添加一个引用将它与engine项目链接，要么就直接添加外部项，将Engine.cpp添加，否则会出现链接错误,另外还可以编辑链接器
//但是添加引用比其他方法更有优势，因为其他方法一旦生成的静态数据库Engine.lib改名，那么就要修改其他东西，而引用是自动的
//而且Engine现在是P51的依赖，那么一旦Engine内部的某些东西发生了改变，然后我们再编译P51，就要编译两者，使用的是最新的代码，不用再编译Engine