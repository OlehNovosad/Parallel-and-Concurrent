# Amdahl's Law

Amdahl's Law is an equation used to estimate the potential speedup of a parallel program. It helps determine the effectiveness of parallelizing a program based on its parallelizable portion.

## The Equation

$$\text{Speedup} = \frac{1}{(1 - P) + \frac{P}{S}}$$

- **P** - the portion of the program that can be parallelized (0 to 1)
- **S** - the speedup of the parallelized part running on multiple processors

### Example: 95% Parallelizable Program

| Processors | Speedup |
|------------|---------|
| 2          | ~1.9    |
| 3          | ~2.7    |
| 4          | ~3.5    |
| 1,000      | ~19.6   |
| 1,000,000  | ~20.0   |

The non-parallelizable **5%** of the program creates a hard upper limit on achievable speedup of **20**.

---

## Limitations on the Effectiveness of Parallelization

The degree of parallelizability directly caps the maximum possible speedup:

- **90%** parallelizable → maximum speedup of **10**
- **75%** parallelizable → maximum speedup of **4**
- **50%** parallelizable → maximum speedup of **2**

---

## Decision-Making in Parallel Programming

- Amdahl's Law helps determine whether parallelizing a program is worthwhile
- Parallel computing is most beneficial for **highly parallelizable** programs
- The costs and overhead of parallelization must be weighed against potential benefits
- Parallelizing everything is not always the best approach, even with multicore processors available
