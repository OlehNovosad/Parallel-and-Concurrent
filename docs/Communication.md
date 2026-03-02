# Communication between Parallel Tasks

- After decomposing a problem into separate tasks, the next step is to establish communication between tasks
- Communication involves **coordinating execution** and **sharing data**

## Types of Task Communication

### Independent Tasks

- Some problems decompose into tasks that don't require data sharing
- **Example:** Frosting cupcakes independently — no communication needed between tasks

### Interdependent Tasks

- Tasks that require information from other tasks to complete their work
- **Example:** Decorating cupcakes in a rainbow pattern — each task needs to know the colors used by neighboring tasks

## Communication Structures

### Point-to-Point Communication

- Direct links between neighboring tasks
- Suitable when each task communicates with a small number of others
- Involves **sender (producer)** and **receiver (consumer)** roles

### Collective Communication

- Used when tasks need to communicate with a larger group
- Includes **broadcasting** (one-to-many) and **scattering/gathering** (distributing and collecting data)

### Centralized Management

- One task acts as a central coordinator for a group of distributed workers
- Can become a **bottleneck** as the number of workers increases
- Divide-and-conquer strategies can help distribute computation and communication load

## Communication Factors to Consider

### Synchronous vs. Asynchronous Communication

- **Synchronous (blocking)** — Tasks wait for communication to complete before continuing
- **Asynchronous (non-blocking)** — Tasks can perform other work while communication is in progress

### Performance Considerations

- **Processing overhead** — Time spent on communication versus data processing
- **Latency** — Time for a message to travel from sender to receiver
- **Bandwidth** — Amount of data that can be communicated per unit of time

## Context-Specific Considerations

- For **multithreaded programs on a single system**, factors like latency and bandwidth may be less critical
- In **distributed systems** across multiple physical machines, intersystem communication factors significantly impact overall performance
