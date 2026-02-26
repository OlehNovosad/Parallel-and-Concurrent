#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>

class Semaphore
{
   public:
    Semaphore(unsigned int init_count) { count_ = init_count; }

    void acquire()
    {
        std::unique_lock<std::mutex> lck(m_);
        while (!count_)
        {
            cv_.wait(lck);
        }
        count_--;
    }

    void release()
    {
        std::unique_lock<std::mutex> lck(m_);
        count_++;
        lck.unlock();
        cv_.notify_one();
    }

   private:
    unsigned int count_;
    std::mutex m_;
    std::condition_variable cv_;
};

Semaphore chargers(4);
std::mutex cout_mutex;

void cell_phone(int id)
{
    chargers.acquire();

    std::unique_lock<std::mutex> cout_lock(cout_mutex);
    std::cout << "Phone " << id << " is charging..." << std::endl;
    cout_lock.unlock();

    srand(id);
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 2000 + 1000));
    std::cout << "Phone " << id << " DONE charging." << std::endl;
    chargers.release();
}

int main(int, char**)
{
    std::thread phones[10];

    for (int i = 0; i < 10; i++)
    {
        phones[i] = std::thread(cell_phone, i);
    }

    for (auto& phone : phones)
    {
        phone.join();
    }

    return 0;
}
