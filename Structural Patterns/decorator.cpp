#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//dynamic decorator

struct Shape
{
	virtual string str() const = 0;
};

struct Circle : Shape
{
	float radius;

	Circle(const float radius)
		:radius{ radius } {}
	
	string str() const override
	{
		ostringstream oss;
		oss << "A circle of radius" << radius;
		return oss.str();
	}

	void resize(float factor)
	{
		radius *= factor;
	}
};

struct Square : Shape
{
	float side;

	Square(const float side)
		:side{ side } {}

	string str() const override
	{
		ostringstream oss;
		oss << "A square, with side" << side;
		return oss.str();
	}
};

//decorator class/struct
struct ColoredShape :Shape
{ 
	Shape& shape;
	string color;

	ColoredShape(Shape& shape, const string& color)
		:shape{ shape },
		color{ color }
	{
	}
	string str() const override
	{
		ostringstream oss;
		oss << shape.str()<<"has color " << color;
		return oss.str();
	}
};



int main() 
{
	//Square square{ 5 };
	//ColoredShape redSquare(square, "red");
	//cout << square.str() << endl << redSquare.str() << endl;

	Circle circle{ 5 };
	ColoredShape redCircle(circle, "red");
	cout << circle.str() << endl << redCircle.str() << endl;
	return 0;
}