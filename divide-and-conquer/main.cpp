#include <iostream>
#include <future>

unsigned long long recursive_sum(const unsigned int lo, const unsigned int hi, const int depth = 0)
{
    if (depth > 3)
    {
        unsigned long long sum = 0;
        for (auto i = lo; i < hi; i++)
        {
            sum += i;
        }
        return sum;
    }
    else
    {
        const auto mid = (hi + lo) / 2;
        // const auto left = recursive_sum(lo, mid);
        auto left = std::async(std::launch::async, recursive_sum, lo, mid, depth + 1);
        const auto right = recursive_sum(mid, hi, depth + 1);
        return left.get() + right;
    }
}

int main()
{
    const unsigned long long total = recursive_sum(0, 1000000000);
    std::cout << total << std::endl;
    return 0;
}
