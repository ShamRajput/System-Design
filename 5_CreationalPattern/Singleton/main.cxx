#include <iostream>
#include "Singleton.hpp"
#include <thread>

void threadFunc() {
    auto instance = SingletonThreadSafe::getInstance();
    std::cout << "Thread-safe Singleton instance address: " << &instance << std::endl;
}

int main() {
    Singleton& instance = Singleton::getInstance();
    std::cout << "Singleton instance address: " << &instance << std::endl;
    Singleton& instance1 = Singleton::getInstance();
    Singleton& instance2 = Singleton::getInstance();
    std::cout << "Singleton instance address: " << &instance1 << std::endl;
    std::cout << "Singleton instance address: " << &instance2 << std::endl;


    // Test thread-safe singleton
    

    std::thread t1(threadFunc);
    std::thread t2(threadFunc);
    t1.join();
    t2.join();
    
    
    return 0;
}
