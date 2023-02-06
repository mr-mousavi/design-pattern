#pragma once

#include "HotDrink.hpp"

struct HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const  override
	{
		return make_unique<Tea>();
	}
};

struct CoffeeFactory :HotDrinkFactory
{
	virtual unique_ptr<HotDrink> make() const override
	{
		return make_unique<Coffee>();
	}
};