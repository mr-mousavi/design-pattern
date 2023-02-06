#include "Person.h"

class Person::PersonImpl
{
public:
	void greet(Person* p);
};

void Person::PersonImpl
::greet(Person* p)
{
	std::cout << p->name 
		<< std::endl;
}

Person::Person()
	:pimpl(new PersonImpl)
{

}

Person::~Person()
{
	delete pimpl;
}

void Person::greet()
{
	this->pimpl->greet(this);
}