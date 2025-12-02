# Non-Comparison Sorting Algorithms

**CS250: Data Structures and Algorithms - Assignment 3**  
**Fall 2025 | BSDS-2**

## 👥 Team Members
- Hamna Shah (507662)
- Zayna Qasim (XXXX)

---

## 📋 Project Overview

This project implements and analyzes five non-comparison sorting algorithms:

1. **Counting Sort (Non-Stable)** - Fast integer sorting without stability guarantees
2. **Counting Sort (Stable)** - Preserves relative order of equal elements
3. **LSD Radix Sort** - Processes digits from least to most significant
4. **Bucket Sort** - Distributes elements across buckets for sorting
5. **MSD Radix Sort** - Top-down recursive digit processing

The implementation includes comprehensive performance benchmarks across various input sizes, data distributions, and value ranges.

---

## 🚀 Quick Start

### Prerequisites
- C++ compiler with C++17 support (g++ 7.0+ or clang++ 5.0+)
- Make (optional, for using Makefile)
- Git

### Clone the Repository
```bash
git clone https://github.com/[your-username]/cs250-noncomparison-sorting.git
cd cs250-noncomparison-sorting
```

### Compile and Run

**Option 1: Using g++ directly**
```bash
g++ -o sorting main.cpp -std=c++17 -O2
./sorting
```

**Option 2: Using Make**
```bash
make
./sorting
```

**Option 3: Without optimization (for debugging)**
```bash
g++ -o sorting main.cpp -std=c++17 -g
./sorting
```

---

## 📁 Repository Structure

```
cs250-noncomparison-sorting/
│
├── README.md                  # This file
├── main.cpp                   # Complete implementation
├── Makefile                   # Build automation
├── report.pdf                 # Detailed analysis report
│
└── results/                   # Output files (generated)
    ├── scalability_test.txt
    ├── distribution_test.txt
    └── range_test.txt
```

---

## 🔧 Compilation Options

### Standard Compilation
```bash
g++ -o sorting main.cpp -std=c++17 -O2
```

### With Debug Symbols
```bash
g++ -o sorting main.cpp -std=c++17 -g
```

### With All Warnings
```bash
g++ -o sorting main.cpp -std=c++17 -O2 -Wall -Wextra
```

### Maximum Optimization
```bash
g++ -o sorting main.cpp -std=c++17 -O3 -march=native
```

---

## 🧪 What the Program Does

When you run the program, it automatically:

1. **Basic Functionality Test**
   - Sorts a small sample array with each algorithm
   - Verifies correctness of each implementation

2. **Performance Benchmarks**
   - Tests arrays of sizes: 1K, 5K, 10K, 50K, 100K
   - Measures execution time for each algorithm
   - Uses random data with range [0, 10×size]

3. **Distribution Tests**
   - Tests on random, sorted, reverse, and duplicate-heavy data
   - Shows how each algorithm handles different patterns

4. **Range Impact Analysis**
   - Tests Counting Sort with small, medium, and large ranges
   - Demonstrates range sensitivity

All results are displayed in the terminal with formatted tables.

---

## 📊 Sample Output

```
======================================
  Non-Comparison Sorting Algorithms  
======================================

========== BASIC FUNCTIONALITY TEST ==========

Original array: [64, 34, 25, 12, 22, 11, 90, 88, 45, 50]

Counting Sort (Non-Stable): [11, 12, 22, 25, 34, 45, 50, 64, 88, 90]
Correctly sorted: YES

========== PERFORMANCE BENCHMARKS ==========

Testing with array size: 10000
------------------------------------------------------------
Counting Sort (Non-Stable):      0.88 ms
Counting Sort (Stable):          1.02 ms
LSD Radix Sort:                  1.65 ms
Bucket Sort:                     1.45 ms
MSD Radix Sort:                  1.78 ms
```

---

## 🎯 Algorithm Descriptions

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

---

## 📈 Key Findings

1. **Counting Sort excels with small ranges** (k ≈ n)
2. **Stability costs ~15% performance** but enables multi-pass algorithms
3. **Radix Sort scales linearly** with digit count
4. **Bucket Sort is distribution-dependent** - great for uniform data
5. **MSD Radix benefits from early termination** on sorted data

---

## 🛠️ Customizing Tests

You can modify the test parameters in `main.cpp`:

### Change Array Sizes
```cpp
vector<int> sizes = {1000, 5000, 10000, 50000, 100000};
```

### Adjust Value Ranges
```cpp
vector<int> testData = createRandomArray(size, size * 10);  // Change multiplier
```

### Add Custom Test Cases
```cpp
vector<int> myData = {/* your values */};
cout << "Custom test: " << benchmarkSort(lsdRadixSort, myData) << " ms" << endl;
```

---

## 📖 Documentation

For detailed algorithm explanations, complexity analysis, and experimental results, see:
- **[report.pdf](report.pdf)** - Complete assignment report with analysis

---

## 🐛 Troubleshooting

### Compilation Errors

**Error: `'chrono' is not a member of 'std'`**
```bash
# Use C++11 or later
g++ -o sorting main.cpp -std=c++17
```

**Error: `undefined reference to 'sqrt'`**
```bash
# Link math library
g++ -o sorting main.cpp -std=c++17 -lm
```

### Runtime Issues

**Program crashes with large arrays:**
- Reduce array sizes in test cases
- Increase system stack size: `ulimit -s unlimited`

**Very long execution times:**
- Reduce test array sizes
- Use optimization flag: `-O2` or `-O3`

---

## 📝 Assignment Requirements Checklist

- [x] Implemented Counting Sort (Stable)
- [x] Implemented Counting Sort (Non-Stable)
- [x] Implemented LSD Radix Sort
- [x] Implemented 2 additional algorithms (Bucket Sort, MSD Radix Sort)
- [x] Explained how each algorithm works
- [x] Described data structures used
- [x] Analyzed time/space complexity
- [x] Conducted performance experiments
- [x] Compared algorithm behavior
- [x] Documented code thoroughly
- [x] Created comprehensive report
- [x] Uploaded to GitHub

---

## 🔗 Resources

- [Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/9780262046305/)
- [C++ Reference - std::vector](https://en.cppreference.com/w/cpp/container/vector)
- [C++ Reference - Chrono](https://en.cppreference.com/w/cpp/chrono)

---

## 📄 License

This project is for educational purposes as part of CS250 coursework.

---

## 🤝 Contributing

This is an academic assignment. Contributions are not accepted.

---

## 📧 Contact

For questions about this implementation:
- Hamna Shah: [your-email]@example.com
- Zayna Qasim: [partner-email]@example.com

---

**Course:** CS250 - Data Structures and Algorithms  
**Institution:** [Your University]  
**Semester:** Fall 2025

---

### ⭐ Acknowledgments

Thanks to our instructor for guidance on algorithm design and analysis techniques.
