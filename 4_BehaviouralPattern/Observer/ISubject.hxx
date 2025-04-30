#pragma once

#include <memory>
class IObserver;
class ISubject {
    public:
        virtual ~ISubject() = default;

        virtual void attach(std::shared_ptr<IObserver>& observer) = 0;
        virtual void detach(std::shared_ptr<IObserver>& observer) = 0;
        virtual void notify() = 0;

};