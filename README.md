# Data Structures & Algorithms in C++

![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=cplusplus&logoColor=white)
![Build examples: C++17](https://img.shields.io/badge/Build_examples-C%2B%2B17-00599C)
[![GitHub Repository](https://img.shields.io/badge/GitHub-Jahidul183019%2FDSA-181717?logo=github)](https://github.com/Jahidul183019/DSA)

**Implement the fundamentals. Understand the patterns. Practice problem solving.**

My personal collection of data structure implementations and algorithmic problem solutions in C++, organized by topic. This repository documents my DSA practice and serves as a reference for revision, interview preparation, and competitive programming.

The repository covers foundational structures, common problem-solving patterns, and advanced topics such as graph algorithms and dynamic programming. Some files compare multiple approaches, including recursion, memoization, tabulation, and space optimization.

## Contents

- [Repository structure](#repository-structure)
- [Topic index](#topic-index)
- [Getting started](#getting-started)
- [Working with solutions](#working-with-solutions)
- [Suggested learning path](#suggested-learning-path)
- [Roadmap](#roadmap)

## Repository structure

Solutions live in topic folders at the repository root. A few examples:

```text
DSA/
├── Arrays/
│   └── product_of_array_except_self.cpp
├── Sorting Algorithms/
│   └── Quick_Sort_Algorithm.cpp
├── Linked List/
│   └── ReverseLinkedList.cpp
├── Graph/
│   ├── BFSTraversal.cpp
│   └── DFSTraversal.cpp
├── Dynamic Programming/
│   ├── House_Robber.cpp
│   └── Longest_Common_Subsequence.cpp
├── … other topic folders listed below
└── README.md
```

## Topic index

Each folder groups implementations and practice problems by topic. Select a topic to browse its source files.

| Topic | Highlights |
| --- | --- |
| [Arrays](Arrays/) | Stock buy and sell, product except self, next permutation, rainwater trapping |
| [2D Arrays](2D%20Arrays/) | Matrix search, spiral traversal, diagonal and row/column sums |
| [Strings](Strings/) | Palindromes, permutations, compression, word reversal |
| [Two Pointer Approach](Two%20Pointer%20Approach/) | Trapping rainwater using two pointers |
| [Sorting Algorithms](Sorting%20Algorithms/) | Bubble, selection, insertion, merge, quick, counting, radix, and DNF sorting |
| [Binary Search](Binary%20Search/) | Rotated arrays, bounds, roots, book allocation, aggressive cows |
| [Recursion and Backtracking](Recursion%20and%20Backtracking/) | Fibonacci, combination sum, palindrome partitioning, maze and knight’s tour problems |
| [Divide & Conquer](Divide%20%26%20Conquer/) | Inversion counting, exponentiation, selection, closest pair of points |
| [Linked List](Linked%20List/) | Singly, doubly, and circular lists; reversal, merging, cycle detection |
| [Stack](Stack/) | Monotonic stacks, parentheses, infix to postfix, min stack, histogram area |
| [Queue](Queue/) | Circular queues, stack/queue conversions, sliding window maximum |
| [Priority Queue](Priority%20Queue/) | Array-based max priority queue and linked-list-based min priority queue |
| [Hashing](Hashing/) | Two sum, three sum, four sum, duplicates, prefix-sum problems |
| [Binary Tree](Binary%20Tree/) | Traversals, views, height, diameter, lowest common ancestor, tree transformations |
| [Binary Search Tree (BST)](Binary%20Search%20Tree%20%28BST%29/) | Construction, validation, iterators, order statistics, recovery |
| [AVL Tree](AVL%20Tree/) | AVL tree insertion |
| [Binary Heap](Binary%20Heap/) | Min heap, max heap, heap sort |
| [Graph](Graph/) | BFS, DFS, shortest paths, minimum spanning trees, topological sorting, connectivity |
| [Disjoint Set Union](Disjoint%20Set%20Union/) | Disjoint set implementation |
| [Greedy](Greedy/) | Fractional knapsack, job scheduling, gas station |
| [Dynamic Programming](Dynamic%20Programming/) | Knapsack, coin change, subsequences, edit distance, grid paths, interval problems |
| [Number Theory](Number%20Theory/) | GCD, LCM, primes, sieve, binary exponentiation, digit problems |
| [Huffman Encoding](Huffman%20Encoding/) | Huffman coding implementation with an input file |
| [STL](STL/) | C++ Standard Template Library examples |

## Getting started

### Prerequisites

- A C++ compiler with C++17 support, such as GCC or Clang.
- Git to clone the repository.
- A terminal and a code editor of your choice.

Some files use the GCC-specific `<bits/stdc++.h>` header. For those files, use GCC or replace that header with the required standard C++ headers when using another compiler.

### Clone the repository

```bash
git clone https://github.com/Jahidul183019/DSA.git
cd DSA
```

### Compile and run an example

From the repository root, compile the quick sort demonstration:

```bash
g++ -std=c++17 "Sorting Algorithms/Quick_Sort_Algorithm.cpp" -o quick_sort
./quick_sort
```

Expected output:

```text
1 8 12 31 32 35
```

The commands above use a macOS/Linux shell. On Windows, run the generated executable using the syntax supported by your terminal, such as `.\quick_sort.exe` in PowerShell.

## Working with solutions

Files are intended to be studied individually. There is no shared application entry point or repository-wide build system.

- **Standalone programs:** Files with a `main()` function can usually be compiled and run individually. Inspect the code to see whether it uses sample data or expects standard input.
- **Online judge snippets:** Some files contain a `Solution` class or functions that rely on a judge-provided environment. Use the relevant judge, or add the necessary headers, data types, and a `main()` driver for local execution.
- **Multiple approaches:** A file may contain several versions of the same class or function. Select one implementation before compiling to avoid redefinition errors.
- **Complexity notes:** Where provided, comments describe time and space complexity. Use them to compare approaches, and check assumptions and edge cases as you practice.

Folder and file names may contain spaces or special characters. Quote paths when using terminal commands.

## Suggested learning path

1. **Build the basics:** Review C++ STL, arrays, strings, sorting, binary search, and number theory.
2. **Practice core patterns:** Work through two pointers, hashing, recursion, backtracking, and divide and conquer.
3. **Implement data structures:** Study linked lists, stacks, queues, heaps, trees, and disjoint sets.
4. **Explore graph algorithms:** Start with BFS and DFS, then move to shortest paths, spanning trees, and connectivity.
5. **Compare optimization strategies:** Practice greedy algorithms and dynamic programming; understand why each approach works.

For each problem, identify the constraints, write a straightforward solution, analyze its complexity, and test edge cases before optimizing.

## Roadmap

- Segment trees and range query techniques.
- More problem solutions and alternative approaches.
- More consistent explanations, complexity notes, and sample inputs/outputs.
