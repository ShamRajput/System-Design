#pragma once 

#include <iostream>
#include <memory>
#include <atomic>
#include <mutex>


class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
private:
    Singleton() = default;
    ~Singleton() = default;
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};



class SingletonThreadSafe {
public:
    SingletonThreadSafe(const SingletonThreadSafe&) = delete;
    SingletonThreadSafe& operator=(const SingletonThreadSafe&) = delete;
private:
    SingletonThreadSafe() = default;
    ~SingletonThreadSafe() = default;
    struct Deleter {
        void operator()(SingletonThreadSafe* instance) {
            delete instance;
        }
    };
public:

    static SingletonThreadSafe* getInstance() {
        std::call_once(mFlag, []() {
            mInstance.reset(new SingletonThreadSafe());
        });
        return mInstance.get();
    }
private:
    inline static std::once_flag mFlag;
    inline static std::unique_ptr<SingletonThreadSafe,Deleter> mInstance;
};