# Algorithm Design and Analysis (ADA) Programs

This repository contains implementations of fundamental algorithms in C++ for analyzing their performance and understanding their behavior.

## Programs Overview

### Program 1: Binary Search with Performance Analysis
Implements recursive binary search algorithm with timing analysis.

**Features:**
- Recursive binary search implementation
- QuickSort preprocessing to ensure sorted array
- Performance measurement using `std::chrono`
- Random array generation for testing

**Algorithm Complexity:**
- Time Complexity: O(log n)
- Space Complexity: O(log n) due to recursion

### Program 2: QuickSort Performance Analysis
Implements QuickSort algorithm with detailed performance measurement.

**Features:**
- In-place QuickSort implementation using last element as pivot
- Performance timing using high-resolution clock
- Random array generation and sorting verification
- Multiple test runs for comprehensive analysis

**Algorithm Complexity:**
- Average Time Complexity: O(n log n)
- Worst Case Time Complexity: O(n²)
- Space Complexity: O(log n)


### Program 3a: Graph Traversal Algorithms (BFS & DFS)
Implements graph traversal algorithms using adjacency list representation.

**Features:**
- Object-oriented graph implementation using C++ class
- Breadth-First Search (BFS) traversal
- Depth-First Search (DFS) traversal
- Support for directed graphs
- Reachability analysis from a given starting node

**Algorithm Complexity:**
- Time Complexity: O(V + E) where V = vertices, E = edges
- Space Complexity: O(V)


### Program 3b: Merge Sort Performance Analysis
Implements Merge Sort algorithm with performance measurement.

**Features:**
- Divide-and-conquer merge sort implementation
- Dynamic memory allocation for temporary arrays
- Performance timing using high-resolution clock
- Memory cleanup to prevent leaks

**Algorithm Complexity:**
- Time Complexity: O(n log n) - guaranteed
- Space Complexity: O(n)


### Program 4: Minimum Spanning Tree Algorithms
Implements both Kruskal's and Prim's algorithms for finding Minimum Spanning Tree (MST).

**Features:**
- **Kruskal's Algorithm:**
  - Edge-based approach using Disjoint Set Union (DSU)
  - Cycle detection using Union-Find data structure
  - Edge sorting by weight
- **Prim's Algorithm:**
  - Vertex-based approach using priority queue
  - Greedy selection of minimum weight edges
  - Adjacency list representation

**Algorithm Complexity:**
- Kruskal's: O(E log E)
- Prim's: O(E log V)

## Input Format Examples

### Program 1 (Binary Search)
```
Enter size: 10
Enter key: 25
```

### Program 2 (QuickSort)
```
Enter size: 1000
```

### Program 3a (Graph Traversal)
```
Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v) for directed graph:
0 1
0 2
1 3
2 3
3 4
1 4
Enter starting node: 0
```

### Program 3b (Merge Sort)
```
Enter size: 1000
```

### Program 4 (MST Algorithms)
```
Enter number of vertices and edges: 4 5
Enter edges (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```

## Key Learning 

1. **Search Algorithms**: Understanding binary search efficiency on sorted data
2. **Sorting Algorithms**: Comparing QuickSort vs MergeSort performance characteristics
3. **Graph Algorithms**: Implementing and comparing BFS vs DFS traversal methods
4. **Greedy Algorithms**: Learning MST algorithms and their different approaches
5. **Performance Analysis**: Measuring algorithm execution time using system clocks
6. **Data Structures**: Working with graphs, priority queues, and disjoint sets

## Notes

- All programs include performance measurement using `std::chrono`
- Random number generation is seeded for reproducible results
- Memory management is handled properly in dynamic allocation scenarios
- Programs follow standard C++ practices and conventions