#include "pch.h"
#include "Observer.h"


Observer::Observer()
{
}


Observer::~Observer()
{
}

void Observer::update()
{
    std::lock_guard<std::mutex> lock(mQueueMutex);

    while (!mQueue.empty())
    {
        this->onNotify(pullEvent());
    }
}

void Observer::pushEvent(const Event & event)
{
    std::lock_guard<std::mutex> lock(mQueueMutex);

    mQueue.push(event);
}

Event Observer::pullEvent()
{
    auto e = mQueue.front();
    mQueue.pop();
    return e;
}
