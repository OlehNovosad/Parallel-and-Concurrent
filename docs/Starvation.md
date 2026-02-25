# Starvation

**Starvation** occurs when a process or thread is **perpetually denied access** to the resources it needs, preventing it from progressing.

## How Starvation Happens

- Ideally, threads will **take turns accessing shared resources**, but this is not guaranteed due to how operating systems schedule thread execution
- A **"greedy" thread** frequently holding a lock on a shared resource can lead to **other threads being starved out** of being able to make progress

## Thread Priorities Impact

In simple scenarios with a few equally prioritized threads, starvation is less likely to be a concern. However, **thread priorities can significantly impact** the likelihood of starvation:

- **Higher-priority threads** are generally scheduled to execute more often
- **Lower-priority threads** may struggle to gain access to resources

## Implications

- **Starvation can significantly impact system performance** and fairness in resource allocation
- Designers of concurrent systems need to **consider thread priorities and the number of concurrent threads** to prevent starvation
- While **occasional delays** in resource access may be tolerable, **persistent starvation** can severely hamper the functionality of affected threads
