#include <array>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

#define PERSONS (5)

int soup_servings = 10;
std::mutex slow_cooker_lid;
std::mutex cout_mutex;
std::condition_variable soup_taken;

void hungry_person(int id)
{
    int put_lid_back = 0;

    while (soup_servings > 0)
    {
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid);
        while ((id != soup_servings % PERSONS) && (soup_servings > 0))
        {
            put_lid_back++;
            soup_taken.wait(lid_lock);
        }

        if (soup_servings > 0)
        {
            soup_servings--;
            lid_lock.unlock();
            if (PERSONS > 2)
            {
                soup_taken.notify_all();
            }
            else
            {
                soup_taken.notify_one();
            }
        }
    }

    std::lock_guard<std::mutex> cout_lock(cout_mutex);
    std::cout << "Person " << id << " put the lid back " << put_lid_back << " times." << std::endl;
}

int main(int, char**)
{
    std::array<std::thread, PERSONS> person;
    for (int i = 0; i < person.size(); i++)
    {
        person[i] = std::thread(hungry_person, i);
    }

    for (int i = 0; i < person.size(); i++)
    {
        person[i].join();
    }

    return 0;
}
