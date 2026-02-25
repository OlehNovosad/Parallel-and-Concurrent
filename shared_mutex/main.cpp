#include <array>
#include <chrono>
#include <iostream>
#include <shared_mutex>
#include <string>
#include <thread>

std::array<std::string, 7> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int today = 0;
std::shared_mutex marker;

void calendar_read(const int id)
{
    for ([[maybe_unused]] const auto& day : week)
    {
        std::shared_lock<std::shared_mutex> lock(marker);
        std::cout << "Reader [" << id << "] sees today is " << week[today] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void calendar_write(const int id)
{
    for ([[maybe_unused]] const auto& day : week)
    {
        std::unique_lock<std::shared_mutex> lock(marker);
        today = (today + 1) % 7;
        std::cout << "Writer [" << id << "] update day to " << week[today] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int, char**)
{
    std::array<std::thread, 10> reader;
    for (int i = 0; i < reader.size(); i++)
    {
        reader[i] = std::thread(calendar_read, i);
    }

    std::array<std::thread, 2> writer;
    for (int i = 0; i < writer.size(); i++)
    {
        writer[i] = std::thread(calendar_write, i);
    }

    for (auto& i : reader)
    {
        i.join();
    }

    for (auto& i : writer)
    {
        i.join();
    }

    return 0;
}
