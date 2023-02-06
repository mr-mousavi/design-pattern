#include <iostream>
#include <list>
#include <string>
#include "Observer.h"
#include "Observable.h"

using namespace std;

class Person : public Observable<Person>
{
private:
    int nationalCode;
    string content;
public:
    Person(int nationalCode, const string &content)

    : nationalCode(nationalCode), content(content) {    }

    int getNationalCode() const {
        return nationalCode;
    }

    void setNationalCode(int nationalCode) {
        if(this->nationalCode==nationalCode)
            return;
        this->nationalCode = nationalCode;
        notify(*this,"nationalCode");
    }

    const string &getContent() const {
        return content;
    }

    void setContent(const string &content) {
        if(this->content.compare(content) ==0)
            return;
        this->content = content;
        notify(*this,"content");
    }
};

class Informer : public  Observer<Person>
{
    int id{rand()};

private:
    void field_changed(Person& src,const std::string& field_name)override
    {
        cout<< "informer id:  " << id << endl;
        cout<< "perosn's " << field_name << " has changed to ";
        if(field_name == "nationalCode") cout <<src.getNationalCode();
        if(field_name == "content") cout <<src.getContent();
        cout<<endl;
    }
};



int main()
{
    Person target{10,"nothing yet"};
    Informer informer;
    target.attach(informer);
    target.setContent("some activity...");

    target.setNationalCode(14);



    return 0;
}











