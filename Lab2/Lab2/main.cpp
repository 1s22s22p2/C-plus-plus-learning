#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	std::string name = "cherno";
	name[2] = 'a';
	std::cout << name << std::endl;     //这里给name新建了个内存内存里面存的时“cherno：

	//std::string& name1 = "cherno";
	//std::string* name1 = "cherno";     //都是不合法的

	char* name1 = (char*)"cherno";
	/*std::string *name2 = name1;
	std::string &name2 = name1;*/
	std::string name2 = name1;           
	name2[2] = 'a';
	std::cout << name2 << std::endl;
	std::cout << name1 << std::endl;     //这里表面上是给了string一个地址，但是string类实例化时会分配一个内存，并不在存储const char的内存上，所以string输出改变，而name1不变，因为实际的地址不一样

	char* name3 = (char*)"cherno";
	const std::string name4 = name1;     
	/*name4[2] = 'a';    */              //报错
	std::string name5 = (std::string)name4;
	name5[2] = 'a';
	std::cout << name3 << std::endl;      //cherno
	std::cout << name4 << std::endl;      //cherno
	std::cout << name5 << std::endl;      //charno
	/*char* name7 = (char*)name4;*/

	/*char* name6 = (char*)"cherno";
	name6[2] = 'a';
	std::cout << "name6=" << name6 << std::endl; */    //无法运行因为无法修改

	std::cin.get();
}