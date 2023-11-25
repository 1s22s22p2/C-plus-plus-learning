#include <iostream>
#include <vector>
#include <string>

struct Vertex
{
	float x, y, z;
	Vertex(float x, float y, float z)
		:x(x), y(y), z(z) {}
	Vertex(const Vertex& other)
		:x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copied Vertex" << std::endl;
	}
};

#define Log(x)	std::cout<<x<<std::endl;

int main()
{
	//std::vector<Vertex> vertices;   //当我们创建Vector时我们实际上时在主函数的当前栈帧中构建它,不复制
	//vertices.push_back({ 1,2,3 });  //将vertex复制然后放入vertices中
	//vertices.push_back({ 4,5,6 });  //将vertex复制然后放入vertices中，进行一次复制，然后为了添加vertex，vertices又复制了一次
	//vertices.push_back(Vertex(7,8,9 ));//将vertex复制然后放入vertices中进行一次复制，然后为了添加vertex，vertices（有两个Vertex）又复制了两次
	// 
	//总共有六次复制,如果有n次这样的操作，那么就要复制n（n+1）/2次
	////优化策略1：我们可以在适当位置构造那个vertex，在vector分配的内存中
	////预先确认要存储的数据量，制造对应的内存,使之没有必要调整大小
	



	//std::vector<Vertex> vertices;   
	///*std::vector<Vertex> vertices1(3);*/    //这个语句实际上会构造三个vertex对象，但我们只想有足够的内存来存储它们
	//vertices.reserve(3);                     //reserve可以确保有足够的内存，不用resize也是一个道理
	//vertices.push_back({ 1,2,3 });  
	//vertices.push_back({ 4,5,6 }); 
	//vertices.push_back(Vertex(7, 8, 9));     //总共有三次复制
	////n次复制

	std::vector<Vertex> vertices;
	vertices.reserve(3);                     
	vertices.emplace_back(1.0f, 2.0f, 3.0f);  //直接在容器底部创造这个元素，省略了拷贝的过程
	vertices.emplace_back(4.0f, 5.0f, 6.0f);
	vertices.emplace_back(7.0f, 8.0f, 9.0f);
	//用emplace那么传递的就不是vertex了而是传递了构造函数的参数列表
	//它要求在vector内存中用以下参数构造一个vertex对象
}
//vector 的原理是如果当前vector的内存不够大，那么就将当前vector的内容从内存的旧位置移到新位置，然后删除旧位置的内存，
//所以当我们尝试push_back一个元素时，如果内存用完就会调整大小重新分配，就会将代码拖慢
//如何避免复制对象，是优化过程中最重要的事情之一