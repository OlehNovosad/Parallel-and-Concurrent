#include <iostream>
#include <mutex>
#include <thread>
#include "boost/thread/latch.hpp"

int bags_of_ships = 1;
std::mutex pencil_mtx;
boost::latch fist_bump(5);

void cpu_work()
{
    unsigned long x = 0;
    for (unsigned long i = 0; i < 1000000; i++)
    {
        x++;
    }
}

void first_shopper()
{
    cpu_work();
    {
        std::scoped_lock<std::mutex> lck(pencil_mtx);
        bags_of_ships += 3;
    }
    fist_bump.count_down();
    std::cout << "First shopper added 3 bags" << std::endl;
}

void second_shopper()
{
    cpu_work();
    fist_bump.wait();
    std::scoped_lock<std::mutex> lck(pencil_mtx);
    bags_of_ships *= 2;
    std::cout << "Second shopper doubled the bags" << std::endl;
}

int main(int, char**)
{
    std::thread shoppers[10];
    for (int i = 0; i < 10; i += 2)
    {
        shoppers[i] = std::thread(first_shopper);
        shoppers[i + 1] = std::thread(second_shopper);
    }

    for (auto& shopper : shoppers)
    {
        shopper.join();
    }

    std::cout << "Total bags of chips: " << bags_of_ships << std::endl;

    return 0;
}
