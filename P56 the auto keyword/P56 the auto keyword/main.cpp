#include <iostream>
#include <vector>
#include <unordered_map>

#define Log(x)	std::cout<<x<<std::endl;

const char* GetName()
{
	return "Cherno";
}

class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

int main()
{
	int a = 5;
	auto b = a;  //它可以自动推断类型
	auto c = 5;  //如果输入5L就是long，5.5f就是float,一旦改变输入类型也会跟着变化
	auto name = GetName();
	/*int a = name.size();*/    //不可以用因为name不是string   //用auto我们可能忽视一些改变，从而产生了破坏性，而且会降低可读性

	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");
	
	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)   //std::vector<std::string>::iterator可以换为auto
	{
		std::cout << *it << std::endl;
	}

	/*using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;*/
	/*typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;*/

	DeviceManager dm;
	const std::unordered_map<std::string, std::vector<Device*>>& devices=dm.GetDevices();
	/*const DeviceMap& devices = dm.GetDevices();*/
	/*const auto& devices = dm.GetDevices();*/       //有三种方法可以缩短长度  //auto前面的const和后面的&不可以少

	std::cin.get();
}

//auto最好在类名相当长的时候才使用