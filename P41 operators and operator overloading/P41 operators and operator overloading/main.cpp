#include <iostream>

#define Log(x)	std::cout<<x<<std::endl;

struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		:x(x), y(y) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
		//同理如果+不是依靠add来定义那么，add也可以用加定义
		//return opera+(other);
		//return *this+other;
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator +(const Vector2& other) const
	{
		return Add(other);
	}

	Vector2 operator *(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}                                               //既写multiply又写*就可以方便使用者

	bool operator ==(const Vector2 other) const
	{
		return (x == other.x) &&(y == other.y);
	}

	bool operator !=(const Vector2 other) const
	{
		/*return !operator==(other);*/
		return !(*this==other);
	}

};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)  //<<接受两个参数一个时输出流，一个是输入流
{
	stream << other.x << "," << other.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result = position.Add(speed.Multiply(powerup));

	Vector2 result1 = position+speed*powerup;

	std::cout << result1 << std::endl;

	std::cin.get();
}