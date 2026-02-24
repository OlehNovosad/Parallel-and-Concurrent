# Parallel and Concurrent Programming

A comprehensive guide to understanding parallel and concurrent computing concepts, architectures, and memory models.

## Contents

### 📚 Core Concepts

#### [1. Sequential vs. Parallel Computing](docs/Sequential_vs_Parallel_Computing.md)

Learn the differences between traditional sequential computing and modern parallel computing approaches.

**Topics:**

- Sequential computing fundamentals
- Parallel computing principles
- Advantages (increased throughput, scalability)
- Challenges (complexity, synchronization overhead)
- Real-world applications

**Key Takeaway:** Parallel computing enables solving larger, more complex problems faster by distributing work across multiple processors.

---

#### [2. Four Classes of Computer Architecture (Flynn's Taxonomy)](docs/Flynn_Taxonomy.md)

Understand the major classifications of parallel computer architectures based on instruction and data streams.

**Architectures:**

- **SISD** - Single Instruction, Single Data (traditional sequential processors)
- **SIMD** - Single Instruction, Multiple Data (GPUs, vector processors)
- **MISD** - Multiple Instruction, Single Data (rarely used)
- **MIMD** - Multiple Instruction, Multiple Data (most common)
  - SPMD (Single Program, Multiple Data)
  - MPMD (Multiple Program, Multiple Data)

**Key Takeaway:** Different architectures suit different types of problems; MIMD is the most widely used in modern computing.

---

#### [3. Shared vs. Distributed Memory](docs/Shared_Distributed_mem.md)

Explore the two main memory organization models in parallel computing systems.

**Memory Models:**

- **Shared Memory Architecture**
  - Uniform Memory Access (UMA)
  - Non-Uniform Memory Access (NUMA)
  - Cache coherency considerations
- **Distributed Memory Architecture**
  - Independent local memory per processor
  - Network-based communication

**Key Takeaway:** Shared memory is easier to program but may not scale well; distributed memory is highly scalable but more complex to program.

---
