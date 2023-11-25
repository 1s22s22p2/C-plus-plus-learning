#include <iostream>
#include <string>   //虽然iostream里面已经定义了string，但是string包含了将它传入输出流

#define Log(x)	std::cout<<x<<std::endl;

//当传入一个只读字符串时使用引用，避免字符串的复制，缩短运行时间
void PrintString(const std::string& string)  //const承诺我们不会修改它 
{
	std::cout << string << std::endl;
}

int main()
{
	//const char* name = "cherno";   //也可以char* name = "cherno"但是不建议，除非要修改这个字符串
	//Log(name);
	////字符串从指针的内存地址开始，知道0结束（0再askll中代表空格）
	//char name2[6] = { 'c','h','e','r','n','o' };  //没有中止符
	//Log(name2);
	//char name3[7] = { 'c','h','e','r','n','o',0 };
	//Log(name3);
	//char name4[7] = { 'c','h','e','r','n','o','\0'};
	//Log(name4);
	//strlen(name);                      //字符串的长度,只使用于const char或者char的，不能输入string
	//strcpy(name3,name2);               //复制字符串，只使用于const char或者char的，不能输入string      

	//c++里面还有std::string
	std::string name = "cherno";/*+"hello";*/       //"cherno"实际上就是const char,赋给了string类,const char不可以相加，但是string可以
	/*std::string name = (std::string)"cherno"+"hello";*/
	
	Log(name);
	name.size();
	name += "hello";
	bool contains = name.find("no") != std::string::npos;     //name.find()返回所找字符串的开始位置，nops表示不存在的位置


	std::cin.get();
}