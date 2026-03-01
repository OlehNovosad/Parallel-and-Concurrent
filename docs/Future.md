# Futures

Asynchronous tasks allow multiple operations to be accomplished simultaneously. Futures are a mechanism for handling the results of asynchronous operations — acting as a placeholder for a result that will be available at a later time. A future is like an **"I owe you"** note for the result of an asynchronous task.

## How Futures Work

> Barron and Olivia demonstrate a future in action using a kitchen analogy:

- Barron asks Olivia to count vegetables in the pantry, representing an asynchronous task
- Olivia provides an "I owe you" note (future) before leaving to complete the task
- Barron continues with other work while holding onto the future
- Olivia eventually returns with the result (zero vegetables), **fulfilling the promise**
- The resolved future allows Barron to make a decision (to go to the store)

## Working with Futures

- **Read-only** - Futures may not have an immediate result and cannot be written to by the requester
- **Blocking** - A thread might need to wait for the future to be resolved before proceeding
- **Resolving / Fulfilling** - Writing the result value to the future, making it available to any waiting threads
