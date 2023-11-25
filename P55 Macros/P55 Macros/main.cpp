#include <iostream>
#include <string>

#define WAIT std::cin.get()      //宏使得WAIT被替换为std::cin.get()，我们实际发送给编译器的代码是替换之后的
#define OPEN_CURLY {             //宏还可以修改任何东西，但是，很多时候没有意义

//#ifdef PR_DEBUG                  //这句话的意思是如果PR_DEBUG被定义，而在DEGUG模式下，我们已经在预处理器定义中定义了
//#define Log(x)	std::cout<<x<<std::endl           //这才是宏真正要应用的地方
//#else
//#define Log(x)
//#endif

//#if 0

#if PR_DEBUG==1                                   //这样子更便于我们调整，只要我们在预处理器定义中修改值,注意预处理器定义中赋值不要有空格
#define Log(x)	std::cout<<x<<std::endl           //这才是宏真正要应用的地方
#elif defined(PR_RELEASE)
#define Log(x)
#endif

/*#endif*/   //可以通过这个方式最整个代码禁用

#define MAIN intmain()\
{\
}                            //宏可以通过反斜杠来换行，\是转义，后面加Enter就是转义Enter，而加空格就是另外的意思，宏必须在同一行，除非有\


int main()
OPEN_CURLY
	Log("Hello");
	WAIT;
}

//宏经常用来处理日志文件，但这涉及隐私不可以给用户看见，所以release中不可以调用宏，而且日志需要时间，所以为了提升软件速度，也不应该将发送给用户的带有日志功能
//为了在Debug中使用宏，在Release中不使用，在项目属性，将配置Debug/win32中C++/预处理器中加入PR__DUG,在release中加PR_RELEASE