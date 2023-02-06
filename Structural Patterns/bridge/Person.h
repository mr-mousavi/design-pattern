#pragma once
#include <iostream>
#include <string>

//pimpl idiom

class Person
{
public:
	Person();
	~Person();
	void greet();
	std::string name;
	class PersonImpl;//inner class
	PersonImpl* pimpl;
};