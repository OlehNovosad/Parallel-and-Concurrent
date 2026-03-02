# Mapping in Parallel Design

- Mapping is the **fourth and final stage** of the parallel design process
- It involves specifying **where each established task will be executed**

## Applicability

- **Not applicable** for single-processor systems or systems with automated task scheduling
- Becomes relevant in **distributed systems** or specialized hardware with multiple parallel processors

## Goals and Strategies

The main goal of mapping is to **minimize total execution time**. Two key strategies are:

- **Increasing concurrency** — Place tasks capable of executing concurrently on different processors
- **Improving locality** — Place frequently communicating tasks on the same processor to keep them close together

## Challenges and Considerations

- These two strategies often **conflict**, requiring design trade-offs
- Dynamic workloads may necessitate **periodic remapping** using dynamic load-balancing techniques
- Mapping algorithm design depends heavily on **program structure** and **hardware specifications**
- Various load-balancing algorithms utilize domain decomposition and agglomeration techniques
