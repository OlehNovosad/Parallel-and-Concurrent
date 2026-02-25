# Livelock

**Livelock** is a situation in concurrent computing where two or more threads block each other from making progress.

Barron and Olivia illustrate a livelock scenario as two overly polite threads that continue to offer the last piece of sushi to the other thread out of politeness, creating a situation where neither can progress.

Unlike **deadlock**, threads in livelock are **actively trying to resolve the problem** but fail to make progress.

## Characteristics of Livelock

- Threads **respond to each other's actions**, creating a cycle of mutual interference
- **All threads are busy**, but their combined efforts prevent any actual accomplishment
- **The program never reaches its end state** or terminates

## Causes and Prevention

**Causes:**

- Livelocks often result from algorithms designed to **detect and recover from deadlocks**
- They occur when **multiple processes simultaneously attempt to resolve a deadlock**

**Prevention:**

- Ensure **only one process takes action** to resolve conflicts
- Use mechanisms like **priority systems** or **random selection** to choose which process acts
