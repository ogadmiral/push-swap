*This project has been created as part of the 42 curriculum by mdamouh.*

# Push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.  
The goal is to sort a list of integers using **two stacks (`a` and `b`)** and a **restricted set of operations**, while producing the **smallest possible number of moves**.

The program receives a sequence of integers as arguments and outputs a list of instructions (such as `sa`, `pb`, `ra`, etc.) that will sort the numbers in ascending order.

This project focuses on:
- Algorithmic thinking
- Data structures (linked lists / stacks)
- Optimization under constraints
- Time and space efficiency

### Algorithm Overview

This implementation uses a **chunk-based sorting strategy**, combined with:
- **Indexing** values instead of sorting raw numbers
- **Small-case optimizations** for 2 to 5 elements
- **Chunk pushing** from stack A to stack B
- **Greedy reconstruction** from stack B to stack A

For small inputs (≤ 5 elements), a dedicated optimal sorting logic is used to guarantee minimal operations.

For large inputs:
1. Values are indexed based on their sorted order.
2. Stack A is divided into chunks.
3. Elements are pushed to stack B chunk by chunk.
4. Stack B is rebuilt back into stack A by always moving the maximum element efficiently.

This approach guarantees:
- Correct sorting
- Efficient operation counts (≤ 5500 for 500 numbers)

---

## Instructions

### Compilation

Compile the program using:

```bash
make

