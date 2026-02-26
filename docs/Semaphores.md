# Semaphores

Semaphores are a synchronization mechanism used to control access to shared resources. Unlike locks or mutexes, semaphores can allow multiple threads to access a resource simultaneously. Semaphores include a counter to track how many times they've been acquired or released.

## Semaphore Functionality

- Threads can acquire a semaphore when its count is positive, decrementing the counter
- If the counter reaches zero, threads attempting to acquire the semaphore are blocked and queued
- Threads release the semaphore when done, incrementing the counter and potentially signaling waiting threads

## Types of Semaphores

### Counting Semaphore

Counting semaphores can have values of 0, 1, 2, 3, and so on, representing the number of available resources. They can be used to manage access to a limited pool of resources, such as database connections or items in a queue.

Barron, Olivia, and Steve demonstrate a counting semaphore using a two-port phone charger:

- The number of available ports represents a semaphore with an initial value of two
- As devices are plugged in, the semaphore value is decremented; when unplugged, the semaphore count is incremented
- When all ports are in use (for example, the semaphore value is 0), additional threads must wait to acquire the semaphore

### Binary Semaphore

Binary semaphores are restricted to one of two values: 0 (locked) or 1 (unlocked). They are similar to mutexes, but with a key difference that any thread can release a semaphore, not just the one that acquired it.

## Key Advantages of Semaphores

- Flexibility in allowing multiple threads to access resources simultaneously
- Ability to function as a signaling mechanism between threads
- Versatility in managing various types of resource pools and synchronization scenarios
