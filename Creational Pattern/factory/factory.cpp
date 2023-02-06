#include <iostream>
#include <cmath>
#include "HotDrinkFactory.hpp"
#include "DrinkFactory.hpp"

using namespace std;


int main()
{
	DrinkFactory df;
	auto c = df.make_drink("tea");
	return 0;
}