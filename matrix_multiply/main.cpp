#include <thread>
#include <chrono>
#include <cstdio>

void sequential_matrix_multiply(long** A, const size_t num_rows_a, const size_t num_cols_a,
                                long** B, const size_t num_rows_b, const size_t num_cols_b,
                                long** C)
{
    for (size_t i = 0; i < num_rows_a; i++)
    {
        for (size_t j = 0; j < num_cols_b; j++)
        {
            C[i][j] = 0;
            for (size_t k = 0; k < num_cols_a; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* parallel implementation of matrix multiply */
void parallel_matrix_multiply(long** A, const size_t num_rows_a, const size_t num_cols_a,
                              long** B, size_t num_rows_b, const size_t num_cols_b,
                              long** C)
{
    auto thread_worker = [&](const size_t start_row, const size_t end_row)
    {
        for (size_t i = start_row; i < end_row; i++)
        {
            for (size_t j = 0; j < num_cols_b; j++)
            {
                C[i][j] = 0;
                for (size_t k = 0; k < num_cols_a; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    };

    constexpr size_t NUM_THREADS = 10;

    std::thread threads[NUM_THREADS];
    const size_t rows_per_thread = num_rows_a / NUM_THREADS;

    for (size_t t = 0; t < NUM_THREADS; t++)
    {
        const size_t start_row = t * rows_per_thread;
        const size_t end_row = (t == NUM_THREADS - 1) ? num_rows_a : start_row + rows_per_thread;
        threads[t] = std::thread(thread_worker, start_row, end_row);
    }

    for (size_t t = 0; t < NUM_THREADS; t++)
    {
        threads[t].join();
    }
}

int main()
{
    constexpr int NUM_EVAL_RUNS = 3;
    constexpr size_t NUM_ROWS_A = 1000;
    constexpr size_t NUM_COLS_A = 1000;
    constexpr size_t NUM_ROWS_B = NUM_COLS_A;
    constexpr size_t NUM_COLS_B = 1000;

    // initialize A and B with values in range 1 to 100
    auto** A = static_cast<long**>(malloc(NUM_ROWS_A * sizeof(long*)));
    auto** B = static_cast<long**>(malloc(NUM_ROWS_B * sizeof(long*)));
    if ((A == nullptr) || (B == nullptr))
    {
        exit(2);
    }
    for (size_t i = 0; i < NUM_ROWS_A; i++)
    {
        A[i] = static_cast<long*>(malloc(NUM_COLS_A * sizeof(long)));
        B[i] = static_cast<long*>(malloc(NUM_COLS_B * sizeof(long)));
        if ((A[i] == nullptr) || (B[i] == nullptr))
        {
            exit(2);
        }
        for (size_t j = 0; j < NUM_COLS_A; j++)
        {
            A[i][j] = rand() % 100 + 1;
            B[i][j] = rand() % 100 + 1;
        }
    }

    // allocate arrays for sequential and parallel results
    auto** sequential_result = static_cast<long**>(malloc(NUM_ROWS_A * sizeof(long*)));
    auto** parallel_result = static_cast<long**>(malloc(NUM_ROWS_A * sizeof(long*)));
    if ((sequential_result == nullptr) || (parallel_result == nullptr))
    {
        exit(2);
    }
    for (size_t i = 0; i < NUM_ROWS_A; i++)
    {
        sequential_result[i] = static_cast<long*>(malloc(NUM_COLS_B * sizeof(long)));
        parallel_result[i] = static_cast<long*>(malloc(NUM_COLS_B * sizeof(long)));
        if ((sequential_result[i] == nullptr) || (parallel_result[i] == nullptr))
        {
            exit(2);
        }
    }

    printf("Evaluating Sequential Implementation...\n");
    std::chrono::duration<double> sequential_time(0);
    sequential_matrix_multiply(A, NUM_ROWS_A, NUM_COLS_A, B, NUM_ROWS_B, NUM_COLS_B, sequential_result);
    for (int i = 0; i < NUM_EVAL_RUNS; i++)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        sequential_matrix_multiply(A, NUM_ROWS_A, NUM_COLS_A, B, NUM_ROWS_B, NUM_COLS_B, sequential_result);
        sequential_time += std::chrono::high_resolution_clock::now() - startTime;
    }
    sequential_time /= NUM_EVAL_RUNS;

    printf("Evaluating Parallel Implementation...\n");
    std::chrono::duration<double> parallel_time(0);
    parallel_matrix_multiply(A, NUM_ROWS_A, NUM_COLS_A, B, NUM_ROWS_B, NUM_COLS_B, parallel_result);
    for (int i = 0; i < NUM_EVAL_RUNS; i++)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        parallel_matrix_multiply(A, NUM_ROWS_A, NUM_COLS_A, B, NUM_ROWS_B, NUM_COLS_B, parallel_result);
        parallel_time += std::chrono::high_resolution_clock::now() - startTime;
    }
    parallel_time /= NUM_EVAL_RUNS;

    // verify sequential and parallel results
    for (size_t i = 0; i < NUM_ROWS_A; i++)
    {
        for (size_t j = 0; j < NUM_COLS_B; j++)
        {
            if (sequential_result[i][j] != parallel_result[i][j])
            {
                printf("ERROR: Result mismatch at row %zu, col %zu!\n", i, j);
            }
        }
    }
    printf("Average Sequential Time: %.2f ms\n", sequential_time.count() * 1000);
    printf("  Average Parallel Time: %.2f ms\n", parallel_time.count() * 1000);
    printf("Speedup: %.2f\n", sequential_time / parallel_time);
    printf("Efficiency %.2f%%\n", 100 * (sequential_time / parallel_time) / std::thread::hardware_concurrency());

    free(A);
    free(B);
    free(sequential_result);
    free(parallel_result);

    return 0;
}
