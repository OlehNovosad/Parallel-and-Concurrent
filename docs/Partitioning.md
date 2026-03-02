# Partitioning: Breaking Down the Problem

- Partitioning involves dividing the problem into discrete chunks of work for distribution among multiple tasks
- At this stage of the design process, the focus is on **maximum decomposition** without considering practical limitations like processor count
- Different decomposition methods may have varying advantages depending on the problem and hardware
- Domain decomposition and functional decomposition offer complementary perspectives on parallel problem-solving

## Domain (Data) Decomposition

- Focuses on dividing the **data** associated with the problem into small, ideally equal-sized partitions
- Computations are then associated with the partitioned data
- **Example:** Decorating a tray of cupcakes — work can be divided into blocks or cyclically

## Functional Decomposition

- Begins by considering all **computational work** required by the program
- Divides the overall work into separate tasks performing different portions
- Data requirements for these tasks are a secondary consideration
- **Example:** Breaking down the process of making cupcakes into individual tasks (mixing, baking, frosting)

## Complementary Approaches

- Domain and functional decomposition are complementary and often used in combination
- Developers typically start with **domain decomposition** as it forms the foundation for many parallel algorithms
- Exploring both approaches can reveal optimization opportunities and potential issues that might be missed by considering data alone
