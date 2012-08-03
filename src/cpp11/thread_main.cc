#include <iostream>
#include <thread>

void hello(){
    std::cout << "Hello World from thread " << std::endl;
}

int main(){
    std::thread t1(hello);
    t1.join();

    return 0;
}
