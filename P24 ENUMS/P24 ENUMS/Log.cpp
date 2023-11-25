#include <iostream>

class Log
{
public:                               
	enum Level
	{
		LevelError=0,LevelWarning=1, LevelInfo=2       //to make our code readable。  //前面的level是为了防止命名重复
	};
	//const int LogLevelWarning = 1;
	//const int LogLevelError = 0;
	//const int LogLevelInfo = 2;       //suitable for enum
private:
	Level m_LogLevel = LevelInfo;
public:
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Warn(const char* message)             
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[Warning]:" << message << std::endl;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[Error]:" << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[Info]:" << message << std::endl;
	}
};

int main()
{
	Log log;
	log.SetLevel(Log::LevelWarning);   //也可以用log.LevelWarning
	log.Warn("hello");
	log.Error("hello");
	log.Info("hello");
	std::cin.get();
}

//在任何用到数字集合的地方都可以选择enum