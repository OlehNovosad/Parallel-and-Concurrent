#include <iostream>
#include <mutex>
#include <thread>
#include "boost/asio.hpp"

std::mutex cout_mtx;

void vegetable_chopper(const int veg_id)
{
    std::scoped_lock<std::mutex> cout_lock(cout_mtx);
    std::cout << "Thread " << std::this_thread::get_id() << " chopped vegetable " << veg_id << std::endl;
}

int main(int, char**)
{
    // Create a pool of threads to chop vegetables
#if 0
    std::thread choppers[100];

    for (int i = 0; i < 100; i++)
    {
        choppers[i] = std::thread(vegetable_chopper, i);
    }

    for (auto& chopper : choppers)
    {
        chopper.join();
    }
#endif

    boost::asio::thread_pool thread_pool(4);

    for (int i = 0; i < 100; i++)
    {
        boost::asio::post(thread_pool, [i] { vegetable_chopper(i); });
    }

    thread_pool.join();

    return 0;
}
