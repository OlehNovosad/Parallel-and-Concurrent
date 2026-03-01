# Thread Pool

## Challenges with Creating Many Threads

> Barron and Olivia introduce the concept of running asynchronous tasks in parallel using a cooking analogy where they each represent independent threads (or processes) chopping different vegetables representing parallel tasks.

- As more tasks (vegetables) are added, they can spawn a new thread for each one
- Creating a new thread for each task can lead to inefficiencies because thread creation incurs overhead in terms of processor time and memory usage

## Thread Pools

Thread pools can be a more efficient alternative to creating individual threads for each task.

- Thread pools maintain a small collection of **worker threads** that can be reused to execute multiple tasks
- Submitting tasks to a thread pool is analogous to adding items to a to-do list for worker threads

## Benefits of Thread Pools

- **Reduced overhead** - Reusing threads from a pool overcomes the cost of creating new threads for each task
- **Better performance** - Especially advantageous when task execution time is less than thread creation time
- **Improved responsiveness** - Using preexisting threads eliminates the delay of thread creation
