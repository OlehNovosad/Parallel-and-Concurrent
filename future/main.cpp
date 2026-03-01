#include <iostream>
#include <future>
#include <chrono>

int future_worker()
{
    std::cout << "Worker thread started" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 42;
}

int main()
{
    std::cout << "Main thread started" << std::endl;
    std::future<int> result = std::async(std::launch::async, future_worker);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Main thread is doing other work..." << std::endl;
    std::cout << "Worker response with: " << result.get() << std::endl;
    return 0;
}
