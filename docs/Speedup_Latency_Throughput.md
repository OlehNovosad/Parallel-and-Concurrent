# Weak Scaling vs. Strong Scaling

## Weak Scaling

**Weak scaling** increases the problem size proportionally with added processors, keeping the workload per processor constant.

- Goal: tackle larger problems in the same amount of time
- Example: one person decorates 10 cupcakes/hour; two people working in parallel decorate 20 cupcakes in the same time

## Strong Scaling

**Strong scaling** breaks down a fixed-size problem across multiple processors to execute it faster.

- Goal: accomplish the same task more quickly
- Example: decorating 10 cupcakes takes one person an hour, but two people working together finish in about 30 minutes

---

## Key Metrics in Parallel Computing

### Throughput

- Measures the number of tasks completed in a given time period
- Adding more processors increases overall throughput
- Example: 10 cupcakes/hour with one worker → 30 cupcakes/hour with three workers

### Latency

- The time taken to execute a single task from start to finish
- Remains constant per task even when multiple processors are used
- Example: six minutes to decorate one cupcake, regardless of how many workers are available

### Speedup

- Calculated as the ratio of sequential execution time to parallel execution time:

$$\text{Speedup} = \frac{T_{\text{sequential}}}{T_{\text{parallel}}}$$

- Example: if one worker takes 60 minutes and two workers take 30 minutes, the speedup is **2**

---

## Limitations of Parallelization

- Real-world programs often have both parallelizable and sequential components
- Sequential parts of a program limit the maximum achievable speedup
- This leads to **diminishing returns** as more processors are added
- Example: packing cupcakes into a shared container must be done sequentially, bottlenecking the parallel decoration work
