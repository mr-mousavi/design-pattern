#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H
#include <string>

class Observer
{
public:
    virtual void field_changed(const std::string& field_name) =0;
};
#endif //OBSERVER_OBSERVER_H
