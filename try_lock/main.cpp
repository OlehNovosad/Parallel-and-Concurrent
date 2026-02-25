#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

unsigned int items_on_notepad = 0;
std::mutex pencil;

void shopper(const char* name) {
    int item_to_add = 0;

    while (items_on_notepad <= 20) {
        if (item_to_add && pencil.try_lock()) {
            items_on_notepad += item_to_add;
            std::cout << name << " added " << item_to_add << " to notepad" << std::endl;
            item_to_add = 0;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            pencil.unlock();
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            item_to_add++;
            std::cout << name << " found something to add" << std::endl;
        }
    }
}

int main(int, char**) {
    auto start_time = std::chrono::steady_clock::now();
    std::thread oleh(shopper, "Oleh");
    std::thread olena(shopper, "Olena");

    oleh.join();
    olena.join();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::steady_clock::now() - start_time)
                            .count();

    std::cout << "Elapsed time: " << elapsed_time / 1000.0 << std::endl;
    return 0;
}
