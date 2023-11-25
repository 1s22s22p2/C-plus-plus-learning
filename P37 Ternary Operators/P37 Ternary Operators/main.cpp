#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

static int s_Level = 1;
static int s_Speed = 2;

int main()
{
	/*if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;*/
	s_Speed = s_Level > 5 ? 10 : 5;  //与上面同义

	/*std::string otherRank;  //实际上会新建一个字符串变量，然后被后面代码中的字符串变量覆盖掉，会更慢
	if (s_Level > 10)
		otherRank = "Master";
	else
		otherRank = "Beginner";*/
	std::string rank = s_Level > 10 ? "Master" : "Beginner";

	/*s_Speed = s_Level > 10 ? (15:(s_Level > 5 ? 10 : 5));*/  //这个不可以
	s_Speed = s_Level > 5 ? s_Level > 10 ? 5 : 10 : 15;
	s_Speed = (s_Level > 5 && s_Level < 100) ? s_Level > 10 ? 5 : 10 : 15;
	s_Speed = (s_Level > 5 && s_Level < 100) ? s_Level > 10 ? 5 : 10 : 15;  //&&优先级大于？
	
	std::cin.get();
}