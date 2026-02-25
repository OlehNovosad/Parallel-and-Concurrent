# Parallel and Concurrent Programming

A comprehensive guide to understanding parallel and concurrent computing concepts, architectures, and memory models.

## Contents

### 📚 Core Concepts

#### [1. Sequential vs. Parallel Computing](docs/Sequential_vs_Parallel_Computing.md)

Learn the differences between traditional sequential computing and modern parallel computing approaches.

**Topics:**

- Sequential computing fundamentals
- Parallel computing principles
- Advantages (increased throughput, scalability)
- Challenges (complexity, synchronization overhead)
- Real-world applications

**Key Takeaway:** Parallel computing enables solving larger, more complex problems faster by distributing work across multiple processors.

---

#### [2. Four Classes of Computer Architecture (Flynn's Taxonomy)](docs/Flynn_Taxonomy.md)

Understand the major classifications of parallel computer architectures based on instruction and data streams.

**Architectures:**

- **SISD** - Single Instruction, Single Data (traditional sequential processors)
- **SIMD** - Single Instruction, Multiple Data (GPUs, vector processors)
- **MISD** - Multiple Instruction, Single Data (rarely used)
- **MIMD** - Multiple Instruction, Multiple Data (most common)
  - SPMD (Single Program, Multiple Data)
  - MPMD (Multiple Program, Multiple Data)

**Key Takeaway:** Different architectures suit different types of problems; MIMD is the most widely used in modern computing.

---

#### [3. Shared vs. Distributed Memory](docs/Shared_vs_Distributed_Memory.md)

Explore the two main memory organization models in parallel computing systems.

**Memory Models:**

- **Shared Memory Architecture**
  - Uniform Memory Access (UMA)
  - Non-Uniform Memory Access (NUMA)
  - Cache coherency considerations
- **Distributed Memory Architecture**
  - Independent local memory per processor
  - Network-based communication

**Key Takeaway:** Shared memory is easier to program but may not scale well; distributed memory is highly scalable but more complex to program.

---

#### [4. Concurrency versus Parallelism in Computing](docs/Concurency_vs_Parallel.md)

Understand the fundamental distinction between concurrency and parallelism, and when each approach is most beneficial.

**Topics:**

- Concurrent execution and program structure
- Parallel execution with multiple processors
- Forms of parallel hardware (multicore, GPUs, clusters)
- Concurrency for I/O-dependent tasks
- Parallelism for computation-intensive tasks

**Key Takeaway:** Concurrency is about program structure and managing multiple things, while parallelism is about doing multiple things simultaneously; concurrency enables potential parallelism but doesn't guarantee it.

---

#### [5. Operating System Scheduling in Concurrent Computing](docs/Execution_Scheduling.md)

Learn how operating systems manage processor resources and schedule threads and processes for execution.

**Topics:**

- Process management and the ready queue
- Multiprocessor handling and resource utilization
- Context switching overhead and frequency
- Preemptive vs. non-preemptive scheduling
- Impact of scheduling on program execution order

**Key Takeaway:** Schedulers handle timing and execution order transparently; programmers should write code that works correctly regardless of specific scheduling decisions made by the OS.

---

#### [6. Thread Lifecycle and States](docs/Thread_Lifecycle.md)

Explore the journey of a thread from creation to termination and the states it transitions through.

**Thread States:**

- **NEW** - Created but not yet running; doesn't consume CPU resources
- **RUNNABLE** - Ready to execute; can be scheduled by the OS
- **BLOCKED** - Waiting for an event or resource; doesn't use CPU resources
- **TERMINATED** - Execution complete; notifies parent thread

**Key Takeaway:** Understanding thread states is crucial for managing concurrent execution and properly coordinating parent-child thread relationships using methods like `join()`.

---

#### [7. Threads vs. Processes](docs/Threads_vs_Process.md)

Compare the characteristics, resource management, and use cases of threads and processes in concurrent systems.

**Key Differences:**

- **Processes** have independent address spaces; **Threads** share address space within a process
- **Processes** are isolated from each other; **Threads** easily share resources and communicate
- **Threads** are lightweight; creating and switching between threads has less overhead
- **Processes** require special mechanisms for communication; **Threads** communicate directly

**Key Takeaway:** Threads are generally preferred due to their lightweight nature and easier resource sharing, though the choice depends on the specific task and system requirements.

---

#### [8. Background Tasks (Detached Threads)](docs/Detached_Threads.md)

Learn how to implement background services and understand the implications of daemon threads.

**Key Concepts:**

- **Daemon Threads** - Background threads that don't prevent program exit
- **Normal Threads** - Prevent program exit until all complete
- **Garbage Collection** - Common example of daemon thread usage
- **Graceful Shutdown** - Considerations for I/O operations in daemon threads

**Key Takeaway:** Daemon threads allow main programs to exit while background tasks run, but abrupt termination may cause issues with I/O operations; use cautiously for non-recovery tasks like garbage collection.

---

#### [9. Data Races in Concurrent Programming](docs/Data_Race.md)

Understand what data races are, how they occur, and why they're difficult to debug in concurrent systems.

**Key Concepts:**

- **Anatomy of a Data Race** - Reading, modifying, and writing operations on shared resources
- **Race Condition** - When two or more threads access the same memory location and at least one modifies it
- **Timing Issues** - Unpredictable thread scheduling leads to different execution outcomes
- **Debugging Challenges** - Intermittent and hard-to-reproduce issues due to timing dependencies

**Key Takeaway:** Data races are a critical concern in concurrent programming; they occur when multiple threads access and modify shared resources without proper synchronization, and their unpredictable nature makes them difficult to identify and resolve.

---

#### [10. Concurrent Access and Critical Sections](docs/Mutual_Execution.md)

Learn how to protect shared resources from data races by using critical sections and mutual exclusion mechanisms.

**Key Concepts:**

- **Critical Sections** - Parts of code that access shared resources and must be protected from simultaneous access
- **Mutex (Mutual Exclusion)** - A lock mechanism that ensures only one thread can execute critical code at a time
- **Atomic Operations** - Single, indivisible operations that cannot be interrupted (e.g., acquiring a lock)
- **Thread Blocking** - Threads wait for a mutex to become available before proceeding
- **Lock Management** - Best practices for keeping critical sections short and efficient

**Key Takeaway:** Protecting critical sections with mutexes prevents data races by ensuring only one thread accesses shared resources at a time; keeping protected code minimal improves efficiency and prevents threads from blocking unnecessarily.

---

#### [11. Reentrant Mutexes](docs/Reentrant_Mutexes.md)

Understand reentrant mutexes and how they prevent deadlocks when the same thread needs to lock a mutex multiple times.

**Key Concepts:**

- **Reentrant Mutex** - A mutex that can be locked multiple times by the same thread; keeps track of lock count internally
- **Recursive Locks** - Alternative name for reentrant mutexes; essential for recursive functions
- **Deadlock Prevention** - Standard mutexes cause deadlock if a thread tries to lock the same mutex; reentrant mutexes prevent this
- **Use Cases** - Nested function calls and recursive functions that need to lock resources

**Key Takeaway:** Reentrant mutexes allow the same thread to acquire the same lock multiple times without deadlocking; they simplify code but require equal numbers of lock and unlock calls.

---

#### [12. Try-Lock](docs/Try_Lock.md)

Learn about non-blocking lock acquisition and how try-locks enable threads to continue with alternative tasks when a resource is unavailable.

**Key Concepts:**

- **Non-Blocking Lock** - Attempts to acquire a lock and immediately returns (true if successful, false if unavailable)
- **Conditional Locking** - Allows threads to check lock availability and proceed with alternative tasks
- **Efficiency** - Prevents threads from blocking when multiple tasks are available
- **Use Cases** - Tasks with multiple independent operations where blocking on one resource is inefficient

**Key Takeaway:** Try-locks enable efficient multitasking by allowing threads to attempt lock acquisition and immediately proceed with alternative work if the resource is unavailable, rather than waiting indefinitely.

---

#### [13. Reader-Writer Locks (Shared Mutexes)](docs/Shared_Mutex.md)

Explore reader-writer locks, which enable better concurrency by allowing multiple threads to read shared data simultaneously while maintaining exclusive write access.

**Key Concepts:**

- **Shared Read Mode** - Multiple threads can acquire the lock concurrently for reading operations
- **Exclusive Write Mode** - Only one thread can hold the lock for writing; no other reads or writes allowed
- **Performance Optimization** - Beneficial when read operations significantly outnumber write operations
- **Implementation Complexity** - More complex to implement than standard mutexes; use more resources

**Key Takeaway:** Reader-writer locks improve concurrency for read-heavy workloads by allowing simultaneous reads while protecting against concurrent writes; however, they're best used when read operations far exceed write operations.

---

#### [14. The Dining Philosophers Problem](docs/Deadlock.md)

Understand the classic synchronization problem that demonstrates how competing for multiple locks can lead to deadlock.

**Key Concepts:**

- **Scenario** - Two philosophers alternate between thinking and eating from a shared plate
- **Chopsticks as Mutexes** - Each philosopher must acquire two locks before entering the critical section
- **Deadlock Condition** - Both philosophers acquire one chopstick each and wait indefinitely for the other
- **Liveness** - The property ensuring concurrent programs make progress, even with resource competition
- **Real-World Example** - Banking applications transferring funds between accounts requiring multiple locks
- **Solution** - Lock prioritization strategy to prevent circular wait conditions

**Key Takeaway:** The Dining Philosophers Problem illustrates how deadlock can occur through multiple lock competition; solutions involve lock ordering and prioritization strategies.

---

#### [15. Abandoned Lock: A New Form of Deadlock](docs/Abandoned_Lock.md)

Learn how unexpected thread termination without releasing locks can create deadlock scenarios.

**Key Concepts:**

- **Definition** - A thread acquires a lock and exits before releasing it, blocking other threads indefinitely
- **Cause** - Unexpected thread termination without automatic lock release
- **Impact** - Other threads waiting for the lock become stuck, unable to proceed
- **Example** - The Dining Philosophers scenario where one philosopher abruptly leaves with a chopstick
- **Root Cause** - Combining resource competition with unexpected termination

**Key Takeaway:** Abandoned locks demonstrate that deadlocks can result not just from resource competition but also from unexpected thread termination; proper error handling and cleanup are essential.

---

#### [16. Starvation](docs/Starvation.md)

Understand how improper thread prioritization and resource allocation can prevent threads from making progress.

**Key Concepts:**

- **Definition** - A thread is perpetually denied access to resources it needs
- **Cause** - Greedy threads holding locks frequently, preventing others from accessing shared resources
- **Thread Priorities** - Higher-priority threads get scheduled more often; lower-priority threads struggle to access resources
- **System Impact** - Significantly affects system performance and fairness in resource allocation
- **Prevention** - Consider thread priorities and limit concurrent threads appropriately

**Key Takeaway:** Starvation occurs when threads are perpetually denied resource access; designers must balance thread priorities and resource competition to ensure all threads can make progress.

---

#### [17. Livelock](docs/Livelock.md)

Explore situations where threads actively attempt to resolve conflicts but end up preventing each other's progress.

**Key Concepts:**

- **Definition** - Multiple threads block each other from making progress through mutual interference
- **Active Response** - Unlike deadlock, threads are continuously trying to resolve the problem but fail
- **Characteristics** - Threads respond to each other's actions, all are busy, but no actual accomplishment occurs
- **Cause** - Deadlock recovery algorithms where multiple processes simultaneously attempt resolution
- **Prevention** - Ensure only one process takes action; use priority systems or random selection

**Key Takeaway:** Livelock differs from deadlock in that threads are actively trying to resolve conflicts but fail through mutual interference; prevention requires ensuring only one process acts at a time.

---
