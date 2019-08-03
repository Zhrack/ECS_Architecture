#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <vector>
#include <mutex>

class Observer;
struct Event;

class Observable
{
public:
    Observable();
    virtual ~Observable();

    void notify(const Event& event);

    void subscribe(Observer* obs);
    void unsubscribe(Observer* obs);

private:
    std::mutex              mMutex;
    std::vector<Observer*>  mObservers;
};


#endif // !OBSERVABLE_H_
