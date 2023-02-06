#pragma once
#include <memory>
#include <map>
#include "HotDrink.hpp"
#include "HotDrinkFactory.hpp"
#include <functional>

using namespace std;

//with below class we will have abstract factory based on inheritance...
class DrinkFactory
{
	map<string, unique_ptr<HotDrinkFactory>> factories;
public:
	DrinkFactory()
	{
		factories["coffee"] = make_unique<CoffeeFactory>();
		factories["tea"] = make_unique<TeaFactory>();
	}

	unique_ptr<HotDrink> make_drink(const string& name)
	{
		auto drink = factories[name]->make();
		//unique_ptr<HotDrink> drink = hot_factories[name]->make();
		drink->prepare(200);
		return drink;
	}
};

//with below class we will have functional factory based on inheritance...
class DrinkWithVolumeFactory
{ 
	map <string, function<unique_ptr<HotDrink>()>> functional_factories;

public:
	DrinkWithVolumeFactory()
	{
		functional_factories["tea"] = [] {
			auto tea = make_unique<Tea>();
			tea->prepare(200);
			return tea;
		};
	}

	unique_ptr<HotDrink> make_drink(const string& name)
	{
		return functional_factories[name]();
	}
};