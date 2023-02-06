#ifndef OBSERVER_OBSERVABLE_H
#define OBSERVER_OBSERVABLE_H
#include <vector>
#include <string>
#include "Observer.h"
#include <algorithm>

class Observable
{
    std::vector<Observer* > observers;
public:
    void notify(const std::string& field_name)
    {
        for(auto observer : observers)
            if(observer)
                observer->field_changed(field_name);
    }
    void attach(Observer& observer)
    {
        observers.push_back(&observer);
    }

    void detach(Observer& observer)
    {
        observers.erase(std::remove(
                observers.begin(),observers.end(),&observer),
                        observers.end());
    }
};
#endif //OBSERVER_OBSERVABLE_H
