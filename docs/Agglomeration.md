# Agglomeration

The agglomeration stage of the parallel design process follows the initial partitioning of a problem into separate tasks and establishing communication between them.

## Granularity

### Fine-Grained Parallelism

- Breaks a program into a **large number of small tasks**
- **Advantages:** Allows for better load balancing across processors
- **Disadvantages:** Increases overhead for communication and synchronization, resulting in a low computation-to-communication ratio

### Coarse-Grained Parallelism

- Splits the program into a **small number of large tasks**
- **Advantages:** Lower communication overhead, allowing more time for computation
- **Disadvantages:** May produce load imbalance — some tasks process more data while others remain idle

### Medium-Grained Parallelism

- Balances the trade-offs between fine and coarse-grained approaches
- Often the most efficient solution for general purpose computers

## Example: Frosting Cupcakes

| Step | Tasks | Communication Events |
|---|---|---|
| Initial partition | 12 (one per cupcake) | 34 |
| After agglomeration | 2 (six cupcakes each) | 2 |

- Tasks were combined to match the number of available processors (two)
- Communication events dropped from 34 to 2, though each event now carries more information

## Recommendations

- Avoid hard-coded limits on the number of tasks
- Use compile-time or runtime parameters to control granularity
- Design programs to adapt to changes in the number of available processors
