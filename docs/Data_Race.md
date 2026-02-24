# Data Races in Concurrent Programming

A data race occurs when two or more threads concurrently access the same memory location AND at least one of those threads is writing to that location to modify its value.

## Table of Contents

- [Anatomy of a Data Race](#anatomy-of-a-data-race)
- [Challenge of Data Races](#challenge-of-data-races)
- [Key Takeaways](#key-takeaways)

## Anatomy of a Data Race

Even simple operations, like incrementing a numeric value, consist of multiple operations:

- **Reading:** A thread reads the existing value from the shared resource
- **Modifying:** The thread performs calculations or modifications based on the value
- **Writing:** The thread writes the new value back to the shared resource

To demonstrate a data race, Barron and Olivia represent two concurrent threads performing different tasks that modify a shared resource: their shopping list. Initially, the list has one clove of garlic. Barron wants to add two cloves, while Olivia wants to add five. Due to thread scheduling and timing issues, the final result is incorrectly three cloves instead of the expected eight.

## Challenge of Data Races

Data races can be difficult to debug because:

- They depend on the unpredictable timing of thread scheduling
- They may occur intermittently, making the problem inconsistent and hard to reproduce

## Key Takeaways

- Data races are a significant concern in concurrent programming
- They occur when multiple threads access and modify shared resources without proper synchronization
- Recognizing potential data races is crucial for developing reliable concurrent programs
- The unpredictable nature of thread scheduling contributes to the complexity of identifying and resolving data races
