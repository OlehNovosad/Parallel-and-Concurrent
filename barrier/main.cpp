#include <iostream>
#include <mutex>
#include <thread>
#include "boost/thread/barrier.hpp"

unsigned int bags_of_chips = 1;
std::mutex pencil_mtx;
boost::barrier fist_bump(10);

void cpu_work(unsigned long worksUnits)
{
    unsigned long x = 0;
    for (unsigned long i = 0; i < worksUnits * 1000000; i++)
    {
        x++;
    }
}

void first_shopper()
{
    cpu_work(1);
    {
        std::scoped_lock<std::mutex> lck(pencil_mtx);
        bags_of_chips += 3;
    }
    std::cout << "First shopper added three bags of chips!" << std::endl;
    fist_bump.wait();
}

void second_shopper()
{
    cpu_work(1);
    fist_bump.wait();
    std::scoped_lock<std::mutex> lck(pencil_mtx);
    bags_of_chips *= 2;
    std::cout << "Second shopper doubled the bags of chips!" << std::endl;
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

    std::cout << "Total bags of chips: " << bags_of_chips << std::endl;

    return 0;
}
