*This project has been created as part of the 42 curriculum by mdamouh.*

# Push_swap

## Description

**Push_swap** is an algorithmic project whose goal is to sort a stack of integers using a limited set of operations, while producing the smallest possible number of instructions.

The project is composed of two parts:

- **Mandatory part (`push_swap`)**: generates a sequence of instructions that sorts stack **a**.
- **Bonus part (`checker`)**: validates whether a given sequence of instructions correctly sorts the stack.

The challenge lies in choosing an efficient algorithm while strictly respecting the allowed operations, memory management rules, and the 42 Norm.

---

## Rules

- You have two stacks: **a** and **b**
- Initially:
  - Stack **a** contains a list of unique integers
  - Stack **b** is empty
- The goal is to sort stack **a** in ascending order
- Only the following operations are allowed:

| Operation | Description |
|---------|-------------|
| sa | swap first two elements of stack a |
| sb | swap first two elements of stack b |
| ss | sa and sb at the same time |
| pa | push top of b to a |
| pb | push top of a to b |
| ra | rotate stack a up |
| rb | rotate stack b up |
| rr | ra and rb at the same time |
| rra | reverse rotate stack a |
| rrb | reverse rotate stack b |
| rrr | rra and rrb at the same time |

---

## Compilation

### Mandatory part

```bash
make
```

This compiles the **push_swap** program.

### Bonus part

```bash
make bonus
```

This compiles the **checker** program in addition to the mandatory part.

### Cleaning rules

```bash
make clean
make fclean
make re
```

---

## Mandatory Part — push_swap

### Usage

```bash
./push_swap 3 2 1
```

Example output:
```
sa
rra
```

- Instructions are printed one per line
- If the input is already sorted, nothing is printed
- On error (duplicates, invalid numbers, overflow), the program prints:

```
Error
```

to **stderr**.

---

## Bonus Part — checker

The **checker** program reads instructions from standard input and applies them to the stacks in order to verify whether the final result is correctly sorted.

### Compilation (bonus)

```bash
make bonus
```

This rule compiles all bonus-specific files required for the checker.

### Usage

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Output:
```
OK
```

If the instructions do not sort stack **a**, or if stack **b** is not empty:
```
KO
```

If an invalid instruction is encountered:
```
Error
```

### Bonus validation rules

- Stack **a** must be sorted in ascending order
- Stack **b** must be empty
- Instructions must be valid and correctly formatted
- Any invalid instruction immediately stops execution and prints `Error`

---

## Algorithm

The sorting strategy is based on:

- Indexing values to normalize data
- Chunk-based sorting for large inputs
- Optimized handling for small stacks (≤ 5 elements)
- Reinsertion from stack **b** to stack **a** in optimal order

This approach allows the program to meet the required benchmarks while remaining simple and efficient.

---

## Benchmarks

The project aims to meet the official 42 benchmarks:

- **100 numbers** sorted in fewer than **700 operations**
- **500 numbers** sorted in fewer than **5500 operations**

---

## Memory Management

- All heap allocations are properly freed
- No memory leaks (verified using Valgrind)
- `get_next_line` static buffers are safely handled in the checker
- No early exits that would prevent proper cleanup

Example test:
```bash
valgrind --leak-check=full ./checker 1 2 3
```

---

## Error Handling

The program prints `Error\n` to **stderr** in the following cases:

- Non-numeric arguments
- Integer overflow
- Duplicate values
- Invalid instructions (checker)

---

## AI Usage

AI tools were used only as assistance to:

- Understand algorithmic concepts
- Debug memory management issues
- Review edge cases and subject compliance

All code was written, reviewed, and fully understood by the author.

---

## Resources

- 42 Push_swap Subject (v10.0)
- https://www.youtube.com/watch?v=N6dOwBde7-M
- https://www.w3schools.com/
- Peer reviews

---

## Author

**mdamouh**  
42 Network
