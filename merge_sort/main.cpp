#include <chrono>
#include <thread>
#include <array>
#include <vector>
#include <cmath>

#define NUM_EVAL_RUNS  (100)
#define ARRAY_SIZE  (100000)

void merge(std::array<int, ARRAY_SIZE>& array, const unsigned int left, const unsigned int mid,
           const unsigned int right)
{
    const size_t num_left = mid - left + 1;
    const size_t num_right = right - mid;

    std::vector<int> array_left(num_left);
    std::vector<int> array_right(num_right);
    std::copy(&array[left], &array[mid + 1], array_left.begin());
    std::copy(&array[mid + 1], &array[right + 1], array_right.begin());

    unsigned int index_left = 0;
    unsigned int index_right = 0;
    unsigned int index_insert = left;

    while ((index_left < num_left) || (index_right < num_right))
    {
        if ((index_left < num_left) && (index_right < num_right))
        {
            if (array_left[index_left] <= array_right[index_right])
            {
                array[index_insert] = array_left[index_left];
                index_left++;
            }
            else
            {
                array[index_insert] = array_right[index_right];
                index_right++;
            }
        }
        else if (index_left < num_left)
        {
            array[index_insert] = array_left[index_left];
            index_left++;
        }
        else if (index_right < num_right)
        {
            array[index_insert] = array_right[index_right];
            index_right++;
        }
        index_insert++;
    }
}

void sequential_merge_sort(std::array<int, ARRAY_SIZE>& array, const unsigned int left, const unsigned int right)
{
    if (left < right)
    {
        unsigned int mid = (left + right) / 2;
        sequential_merge_sort(array, left, mid);
        sequential_merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void parallel_merge_sort(std::array<int, ARRAY_SIZE>& array, const unsigned int left, const unsigned int right,
                         unsigned int depth = 0)
{
    static const auto max_depth = static_cast<unsigned int>(
        std::log2(std::max(1u, std::thread::hardware_concurrency()))
    );
    if (left < right)
    {
        unsigned int mid = (left + right) / 2;
        if (depth < max_depth)
        {
            std::thread left_thread(parallel_merge_sort, std::ref(array), left, mid, depth + 1);
            std::thread right_thread(parallel_merge_sort, std::ref(array), (mid + 1), right, depth + 1);
            left_thread.join();
            right_thread.join();
        }
        else
        {
            parallel_merge_sort(array, left, mid, depth + 1);
            parallel_merge_sort(array, mid + 1, right, depth + 1);
        }
        merge(array, left, mid, right);
    }
}

int main()
{
    std::array<int, ARRAY_SIZE> original_array{}, sequential_result{}, parallel_result{};
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        original_array[i] = rand();
    }

    printf("Evaluating Sequential Implementation...\n");
    std::chrono::duration<double> sequential_time(0);
    std::copy(original_array.begin(), original_array.end(), sequential_result.begin());
    sequential_merge_sort(sequential_result, 0, ARRAY_SIZE - 1); // "warm up"
    for (int i = 0; i < NUM_EVAL_RUNS; i++)
    {
        std::copy(original_array.begin(), original_array.end(), sequential_result.begin()); // reset result array
        auto start_time = std::chrono::high_resolution_clock::now();
        sequential_merge_sort(sequential_result, 0, ARRAY_SIZE - 1);
        sequential_time += std::chrono::high_resolution_clock::now() - start_time;
    }
    sequential_time /= NUM_EVAL_RUNS;

    printf("Evaluating Parallel Implementation...\n");
    std::chrono::duration<double> parallel_time(0);
    std::copy(original_array.begin(), original_array.end(), parallel_result.begin());
    parallel_merge_sort(parallel_result, 0, ARRAY_SIZE - 1); // "warm up"
    for (int i = 0; i < NUM_EVAL_RUNS; i++)
    {
        std::copy(original_array.begin(), original_array.end(), parallel_result.begin()); // reset result array
        auto start_time = std::chrono::high_resolution_clock::now();
        parallel_merge_sort(parallel_result, 0, ARRAY_SIZE - 1);
        parallel_time += std::chrono::high_resolution_clock::now() - start_time;
    }
    parallel_time /= NUM_EVAL_RUNS;

    // verify sequential and parallel results are same
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (sequential_result[i] != parallel_result[i])
        {
            printf("ERROR: Result mismatch at index %d!\n", i);
        }
    }
    printf("Average Sequential Time: %.2f ms\n", sequential_time.count() * 1000);
    printf("  Average Parallel Time: %.2f ms\n", parallel_time.count() * 1000);
    printf("Speedup: %.2f\n", sequential_time / parallel_time);
    printf("Efficiency %.2f%%\n", 100 * (sequential_time / parallel_time) / std::thread::hardware_concurrency());

    return 0;
}
