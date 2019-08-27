#include <thread>
#include <iostream>

void threadFunc() {
    std::cout << "This is a thread!" << std::endl;
}

int main() {
    std::thread t(threadFunc);
    t.join();
    std::cout << "This is main program!" << std::endl;
    return 0;
}