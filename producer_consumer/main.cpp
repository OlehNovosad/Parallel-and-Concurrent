#include <array>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#define BOWL_AMOUNT (10000)
#define CONSUMERS (2)
#define PRODUCERS (1)

class ServingLine
{
   public:
    void serve_soup(int i)
    {
        std::unique_lock<std::mutex> soup_lock(soup_mutex);
        soup_queue.push(i);
        soup_lock.unlock();
        soup_cv.notify_one();
    }

    int take_soup()
    {
        std::unique_lock<std::mutex> soup_lock(soup_mutex);
        soup_cv.wait(soup_lock, [this] { return !soup_queue.empty(); });
        int bowl = soup_queue.front();
        soup_queue.pop();
        return bowl;
    }

   private:
    std::queue<int> soup_queue;
    std::mutex soup_mutex;
    std::condition_variable soup_cv;
};

void soup_producer(ServingLine& servingLine)
{
    for (int i = 0; i < BOWL_AMOUNT; i++)
    {
        servingLine.serve_soup(i);
    }

    servingLine.serve_soup(-1);  // indicate no more soup
    std::cout << "Producer is done serving soup!" << std::endl;
}

void soup_consumer(ServingLine& servingLine)
{
    int soup_eaten = 0;

    while (true)
    {
        int bowl = servingLine.take_soup();
        if (bowl == -1)
        {
            std::cout << "Consumer ate " << soup_eaten << " bowl of soup." << std::endl;
            servingLine.serve_soup(-1);
            return;
        }
        else
        {
            soup_eaten += bowl;
        }
    }
}

int main(int, char**)
{
    ServingLine servingLine;

    std::array<std::thread, CONSUMERS> consumers;
    std::array<std::thread, PRODUCERS> producers;
    for (int i = 0; i < CONSUMERS; i++)
    {
        consumers[i] = std::thread(soup_consumer, std::ref(servingLine));
    }

    for (int i = 0; i < PRODUCERS; i++)
    {
        producers[i] = std::thread(soup_producer, std::ref(servingLine));
    }

    for (int i = 0; i < CONSUMERS; i++)
    {
        consumers[i].join();
    }

    for (int i = 0; i < PRODUCERS; i++)
    {
        producers[i].join();
    }

    return 0;
}
