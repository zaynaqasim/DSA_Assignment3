# Non-Comparison Sorting Algorithms
## CS250: Data Structures and Algorithms - Assignment 3
## Fall 2025 | BSDS-2

## Team Members
- Hamna Shah (507662)
- Zayna Qasim (501288)

## Project Overview
This project implements and analyzes five non-comparison sorting algorithms:

- **Counting Sort (Non-Stable)** - Fast integer sorting without stability guarantees
- **Counting Sort (Stable)** - Preserves relative order of equal elements
- **LSD Radix Sort** - Processes digits from least to most significant
- **Bucket Sort** - Distributes elements across buckets for sorting
- **MSD Radix Sort** - Top-down recursive digit processing

The implementation includes comprehensive performance benchmarks across various input sizes, data distributions, and value ranges.

## What the Program Does

When you run the program, it automatically:

### 1. Basic Functionality Test
- Sorts a small sample array with each algorithm
- Verifies correctness of each implementation

### 2. Performance Benchmarks
- Tests arrays of sizes: 1K, 5K, 10K, 50K, 100K
- Measures execution time for each algorithm
- Uses random data with range [0, 10×size]

### 3. Distribution Tests
- Tests on random, sorted, reverse, and duplicate-heavy data
- Shows how each algorithm handles different patterns

### 4. Range Impact Analysis
- Tests Counting Sort with small, medium, and large ranges
- Demonstrates range sensitivity

All results are displayed in the terminal with formatted tables.


## Algorithm Descriptions

### Counting Sort (Non-Stable)
- **Time Complexity:** O(n + k)
- **Space Complexity:** O(k)
- **Best for:** Small integer ranges
- **Stability:** No

Counts occurrences and places elements directly.

### Counting Sort (Stable)
- **Time Complexity:** O(n + k)
- **Space Complexity:** O(n + k)
- **Best for:** When stability is required
- **Stability:** Yes

Uses cumulative counts and backward traversal.

### LSD Radix Sort
- **Time Complexity:** O(d × n)
- **Space Complexity:** O(n)
- **Best for:** Fixed-width integers
- **Stability:** Yes

Processes digits from right to left using stable counting sort.

### Bucket Sort
- **Time Complexity:** O(n + k) average, O(n²) worst
- **Space Complexity:** O(n + k)
- **Best for:** Uniformly distributed data
- **Stability:** Can be stable

Distributes elements into buckets and sorts each.

### MSD Radix Sort
- **Time Complexity:** O(d × n)
- **Space Complexity:** O(n + d log n)
- **Best for:** Variable-length keys
- **Stability:** Can be stable

Recursive top-down approach with early termination.

## Key Findings
- Counting Sort excels with small ranges (k ≈ n)
- Stability costs ~15% performance but enables multi-pass algorithms
- Radix Sort scales linearly with digit count
- Bucket Sort is distribution-dependent - great for uniform data
- MSD Radix benefits from early termination on sorted data

