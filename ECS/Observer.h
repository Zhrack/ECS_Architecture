#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <queue>
#include <mutex>

#include "Events.h"

class Observer
{
public:
    Observer();
    virtual ~Observer();

    virtual void onNotify(const Event& event) = 0;

    void pushEvent(const Event& event);

protected:
    void update();

private:
    Event pullEvent();

private:
    std::mutex          mQueueMutex;
    std::queue<Event>   mQueue;
};


#endif // !OBSERVER_H_
