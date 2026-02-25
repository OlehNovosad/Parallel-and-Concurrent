# Abandoned Lock: A New Form of Deadlock

## Definition

An **abandoned lock** occurs when a thread acquires a lock on a shared resource and exits before releasing its lock on that resource, leaving other threads trying to acquire the lock to wait indefinitely.

## How It Happens

- When a thread or process acquires a lock and then **terminates unexpectedly**, it may not release the lock automatically
- The lock remains held indefinitely, blocking other threads from accessing the shared resource

## Example: Dining Philosophers

Barron and Olivia demonstrate an abandoned lock scenario as two dining philosophers sharing a chopstick:

- **Barron** (one philosopher) acquires a lock on the shared chopstick and then **abruptly leaves**
- **Olivia** (other tasks) becomes stuck, waiting indefinitely for a lock that will never be released
- This results in a deadlock scenario

## Key Takeaway

Deadlocks can occur not only through resource competition but also through **unexpected thread termination**.
