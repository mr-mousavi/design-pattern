#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H
#include <string>
template <typename T>
class Observer
{
public:
    virtual void field_changed(T& src,const std::string& field_name) =0;
};

#endif //OBSERVER_OBSERVER_H
