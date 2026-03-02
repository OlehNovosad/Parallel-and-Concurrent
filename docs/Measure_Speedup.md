# Measuring Speedup and Efficiency

- **Amdahl's Law** estimates potential speedup from parallelization
- **Empirical measurement** provides actual performance data

## Calculating Speedup

$$\text{Speedup} = \frac{\text{Time}_{sequential}}{\text{Time}_{parallel}}$$

- Speedup measures the benefit of parallel problem-solving
- Any speedup **> 1** indicates improvement from parallelization
- Speedup **< 1** suggests that a sequential algorithm is preferable

**Example:** Measuring how long it takes to add up shopping receipts:

| Scenario | Time |
|---|---|
| Sequential (alone) | 25 seconds |
| Parallel (together) | 17 seconds |

$$\text{Speedup} = \frac{25}{17} \approx 1.47 \text{ (almost 1.5× faster)}$$

## Calculating Efficiency

$$\text{Efficiency} = \frac{\text{Speedup}}{\text{Number of processors}}$$

- Efficiency describes how well processors are utilized
- With **2 processors**: speedup of 1.47 → efficiency of **73.5%**
- With **8 processors**: speedup of 2.2 → efficiency of **27.5%**

## Benchmarking Best Practices

- Limit other running programs to avoid resource competition
- Average multiple independent runs to account for execution variability
- Allow for "warm-up" in environments with just-in-time compilation
- Run the algorithm once before measurement to ensure a consistent cache state
