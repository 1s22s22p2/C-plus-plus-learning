#include <iostream>

class Log
{
public:                                //with more public to separate
	const int LogLevelWarning = 1;
	const int LogLevelError = 0;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel=LogLevelInfo;
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}

	void Warn(const char* message)             //const char* means string
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[Warning]:" << message << std::endl;
	}

	void Error(const char* message)             
	{
		if(m_LogLevel >=LogLevelError)
			std::cout << "[Error]:" << message << std::endl;
	}

	void Info(const char* message)             
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[Info]:" << message << std::endl;
	}
};

int main()
{	
	Log log;
	log.SetLevel(log.LogLevelWarning);     //only the warning and the error will be printed
	log.Warn("hello");
	log.Error("hello");
	log.Info("hello");
	std::cin.get();
}