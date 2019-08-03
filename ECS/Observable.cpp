#include "pch.h"
#include "Observable.h"

#include "Observer.h"


Observable::Observable()
{
}


Observable::~Observable()
{
}

void Observable::notify(const Event& event)
{
    // push event to observers
    for (auto obs : mObservers)
    {
        obs->pushEvent(event);
    }
}

void Observable::subscribe(Observer * obs)
{
    std::lock_guard<std::mutex> lock(mMutex);

    mObservers.push_back(obs);
}

void Observable::unsubscribe(Observer * obs)
{
    std::lock_guard<std::mutex> lock(mMutex);

    for (auto it = mObservers.begin(); it != mObservers.end(); it++)
    {
        if (*it == obs)
        {
            std::iter_swap(it, mObservers.end());

            mObservers.pop_back();
            return;
        }
    }
}
