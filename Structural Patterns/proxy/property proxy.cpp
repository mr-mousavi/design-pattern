#include <iostream>

#include <memory>
using namespace std;


//////////////////////////////////property proxy /////////////////////////////
template <typename T> 
struct Property
{
	T value;

	Property(T val)
	{
		cout << "Property constructor\n";
		*this = val; 
		cout << *this << endl; //its possible because we declare operator T()
	}

	operator T()//to print value of type T
	{
		cout << "operator T()\n";
		return value;
	}

	T operator =(const T&  new_value) //to assign value to type of T
	{
		cout << "Assignment\n";
		return value = new_value;
	}
};

struct Creature
{
	Property<int> strength{ 10 };
	Property<int> agility{ 10 };
};

int main()
{
	Creature creature;
	cout << "-----"<<endl;
	creature.strength = 11;
	int a = creature.agility;
	cout << creature.strength << endl;
	return 0;
}


