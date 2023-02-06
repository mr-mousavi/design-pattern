#ifndef OBSERVER_OBSERVABLE_H
#define OBSERVER_OBSERVABLE_H
#include <vector>
#include <string>
#include "Observer.h"
#include <algorithm>
#include <mutex>
template <typename> struct Observer;

template <typename T>
class Observable
{
public:
    std::vector<Observer<T>*> observers;
//    typedef  std::mutex mutext_t;//first approach
    typedef  std::recursive_mutex mutext_t;//first approach
    mutext_t mtx;

    void notify(T& source,const std::string& field_name)
    {
        std::scoped_lock<mutext_t> lock{mtx};
        for(auto observer : observers)
            if(observer)
                observer->field_changed(source,field_name);
    }
    void attach(Observer<T>& observer)
    {
        std::scoped_lock<mutext_t> lock{mtx};
        observers.push_back(&observer);
    }
    void detach(Observer<T>& observer)
    {
        std::scoped_lock<mutext_t> lock{mtx};
        observers.erase(
                std::remove(observers.begin(), observers.end(), &observer),
                observers.end());
//        auto it= std::find(begin(observers),end(observers), & observer);
//        if(it != std::end(observers))
//            *it = nullptr;
    }
};

#endif //OBSERVER_OBSERVABLE_H
