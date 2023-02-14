#include <iostream>
#include <string>
#include <memory>
#include <variant>
using namespace std;

//classic visitor pattern URL:
// https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Visitor



//usage of visitor at std::visit()

class AddressPrinter
{
public:
    void operator()(const string& houseName)
    {
        cout<<"house name is "<< houseName<<endl;
    }

    void operator()(const int& houseNumber)
    {
        cout<<"house No is "<< houseNumber<<endl;
    }
};

int main() {
variant<string ,int> house;
//house="my home";
house=125;

AddressPrinter ap;
std::visit(ap,house);
    return 0;
}
