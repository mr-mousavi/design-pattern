#include <iostream>
#include <string>
#include "Observer.h"
#include "Observable.h"

using namespace std;

class Person :public Observable
{
    int nationalCode;
    string content;
public:
    Person(){}
    Person(int nationalCode, const string &content)
    : nationalCode(nationalCode), content(content) {}

    int getNationalCode() const {
        return nationalCode;
    }

    void setNationalCode(int nationalCode) {
       if(this->nationalCode == nationalCode) return;
       this->nationalCode = nationalCode;
       notify("nationalCode");
    }

    const string &getContent() const {
        return content;
    }

    void setContent(const string &content) {
        if(this->content.compare(content) ==0) return;
        this->content = content;
        notify("content");
    }
};

class Informer :public Observer
{
public:
    explicit Informer(Person& src) :src(src) {    }

private:
    Person& src;
    int id{rand()};
    void field_changed(const std::string& field_name) override
    {
        cout<<"informer id: "<<id<<endl;
        cout<<"perosn's "<<field_name<<" has changed to ";
        if(field_name == "nationalCode") cout<< src.getNationalCode();
        if(field_name == "content") cout <<src.getContent();
        cout<<endl;
    }
};

int main() {

    Person target{110234, "nothing yet"};
    Informer informer{target};
    target.attach(informer);

    target.setContent("some activity...");
    target.setNationalCode(852285);

    return 0;
}