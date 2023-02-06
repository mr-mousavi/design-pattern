#include <iostream>

using namespace std;

struct Address
{
    string street, city;
    int suite;

    Address(const string& street, const string& city, int suite) :
        street(street), city(city), suite(suite) {}

    Address(const Address& other)
        : street{ other.street }, city{ other.city }, suite{ other.suite }
    {}

    friend ostream& operator<<(ostream& os, const Address& obj)
    {
        return os
            << "street: " << obj.street
            << " city: " << obj.city
            << " suite: " << obj.suite;
    }
};

struct Contact
{
    string name;

    //Address address;
    //Contact(const string& name, Address address) :
       // name(name), address(address) {}

        //instead of storing full object of Address we can keep a pointer of that object.... 
    //here we need to deep copy instead of shallow copy..
    Address* address;
    Contact(const string& name, Address* address) :
        name(name), address(address) {}


    //Contact(const Contact& other) 
    //    : name{other.name}
    //    , address{ new Address{
    //    other.address->street, other.address->city,other.address->suite}}
    //{

    //}

    //if we create copy constructor of Address we need pass value of other.address to new Address...
    Contact(const Contact& other)
        : name{ other.name }
        , address{ new Address{*other.address} }
    {

    }

    friend ostream& operator <<(ostream& os, const Contact& obj)
    {
        return os
            << "name: " << obj.name
            << " works at " << *obj.address; // for pointer of Address 
    }
};

struct PersonFactory
{
    static unique_ptr<Contact> newPerson(const string& name, int suite)
    {
        static Contact proto{ "", new Address{ "123 East Dr", "London", 0 } };
        return clone(name, suite, proto);
    }

private:
    static unique_ptr<Contact> clone(const string& name, const int& suite, Contact& proto)
    {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};


int main()
{

    auto john = PersonFactory::newPerson("john", 123);
    unique_ptr<Contact> jane = PersonFactory::newPerson("jane", 103);
    //we can create multi copy of newPerson....
    cout << *john << endl << *jane << endl;

    return 0;
}