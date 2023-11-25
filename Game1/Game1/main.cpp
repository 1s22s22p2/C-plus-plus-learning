#include<iostream>
#include<string>

int x = 5;
int y = 6;

void function();

int main()
{
	function();
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	int y = 7;
	std::cout << y << std::endl;

	char a[2][3] = {"st","ab"};
	/*a[0] = "s";*/
	char b[5] = "abcd";
	char c[5];
	/*c = "abcd";*/
	strcpy_s(c, "abcd");
	std::cin.getline(c,5,'?');
	std::cout << c << std::endl;
	char k[20] = "abcd""abcd";
	std::cout << k << std::endl;

	std::string f = "abcd";
	std::string e = f + "abc";

}


void function()
{
	static int x = 3;
	int y = 7;
	std::cout << x << std::endl;

}