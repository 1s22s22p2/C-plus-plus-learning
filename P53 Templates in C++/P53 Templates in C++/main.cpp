#include <iostream>
#include <string>


//函数重载
//void Print(int value)
//{
//	std::cout << value << std::endl;
//}
//
//void Print(float value)
//{
//	std::cout << value << std::endl;
//}
//
//void Print(std::string string)
//{
//	std::cout << string << std::endl;
//}

//模板
template<typename T>       //tempalte表示这是个模板，它会在编译时被评估，typename是模板参数，T是名字           
void Print(T value)
{
	std::cout << value << std::endl;
}                         //这并不是真正的函数，只有当我们实际调用它时，这些函数才被真的创建

//模板可以用在类上,而且不止可以用于指定类型
template<typename T, int N>
class Array
{
private:
	T m_Array[N];   //这样就可以在普通的数组中使用变量
public:
	int GetSize() const
	{
		return N;
	}
};


int main()
{
	Print(5);            //它的实际形式是Print<int>(5);它隐式得从参数中获取了类型T是什么
	Print("hello");
	Print(5.5f);
	Array<int, 5> array;     //创建这个类的一个版本将将N替换为5
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}

//模板不可以太复杂，因为太复杂可读性会下降