# Algorithm Design and Analysis (ADA) Programs

This repository contains implementations of fundamental algorithms in C++ for analyzing their performance and understanding their behavior. Each program is designed to be educational and includes detailed explanations suitable for learners at all levels.

## Table of Contents
- [Basic Programs (1-4)](#basic-programs)
- [Greedy Algorithms (5-6)](#greedy-algorithms)
- [Dynamic Programming (7-8)](#dynamic-programming)
- [Advanced Algorithms (9-10)](#advanced-algorithms)
- [Key Concepts Explained](#key-concepts-explained)

---

## Basic Programs

### Program 1: Binary Search with Performance Analysis
**File:** [program1.cpp](program1.cpp)

**What it does:**  
Searches for a specific number in a sorted list of numbers very quickly by repeatedly dividing the search area in half.

**Real-world analogy:**  
Like finding a word in a dictionary - you open it in the middle, check if your word comes before or after, then repeat with the relevant half.

**Features:**
- Recursive binary search implementation
- QuickSort preprocessing to ensure sorted array
- Performance measurement using `std::chrono`
- Random array generation for testing

**Algorithm Complexity:**
- Time Complexity: O(log n) - very fast, even for large datasets
- Space Complexity: O(log n) due to recursion

**Input Example:**
```
Enter size: 10
Enter key: 25
```

**Usage:**
```bash
g++ program1.cpp -o program1
./program1
```

---

### Program 2: QuickSort Performance Analysis
**File:** [program2.cpp](program2.cpp)

**What it does:**  
Sorts a list of numbers by selecting a "pivot" element and arranging all smaller elements before it and larger elements after it, then repeating this process.

**Real-world analogy:**  
Like organizing a deck of cards by picking one card and placing all smaller cards to its left and larger cards to its right, then doing the same for each group.

**Features:**
- In-place QuickSort implementation using last element as pivot
- Performance timing using high-resolution clock
- Random array generation and sorting verification
- Multiple test runs for comprehensive analysis

**Algorithm Complexity:**
- Average Time Complexity: O(n log n)
- Worst Case Time Complexity: O(n²) - rare, happens with already sorted data
- Space Complexity: O(log n)

**Input Example:**
```
Enter size: 1000
```

**Usage:**
```bash
g++ program2.cpp -o program2
./program2
```

---

### Program 3a: Graph Traversal Algorithms (BFS & DFS)
**File:** [program3a.cpp](program3a.cpp)

**What it does:**  
Explores all nodes (points) in a graph (network) using two different strategies: breadth-first (level by level) and depth-first (going as deep as possible first).

**Real-world analogy:**  
- **BFS**: Like exploring a building floor by floor
- **DFS**: Like exploring one hallway completely before moving to the next

**Features:**
- Object-oriented graph implementation using C++ class
- Breadth-First Search (BFS) traversal
- Depth-First Search (DFS) traversal
- Support for directed graphs (one-way connections)
- Reachability analysis from a given starting node

**Algorithm Complexity:**
- Time Complexity: O(V + E) where V = vertices (nodes), E = edges (connections)
- Space Complexity: O(V)

**Input Example:**
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

**Usage:**
```bash
g++ program3a.cpp -o program3a
./program3a
```

---

### Program 3b: Merge Sort Performance Analysis
**File:** [program3b.cpp](program3 b).cpp)

**What it does:**  
Sorts a list by dividing it into smaller pieces, sorting those pieces, then merging them back together in order.

**Real-world analogy:**  
Like organizing two separate sorted piles of papers into one sorted pile by repeatedly picking the smallest paper from the top of either pile.

**Features:**
- Divide-and-conquer merge sort implementation
- Dynamic memory allocation for temporary arrays
- Performance timing using high-resolution clock
- Memory cleanup to prevent leaks

**Algorithm Complexity:**
- Time Complexity: O(n log n) - guaranteed, always the same speed
- Space Complexity: O(n) - needs extra memory

**Input Example:**
```
Enter size: 1000
```

**Usage:**
```bash
g++ program3b.cpp -o program3b
./program3b
```

---

### Program 4: Minimum Spanning Tree Algorithms
**File:** [program4.cpp](program4.cpp)

**What it does:**  
Finds the cheapest way to connect all points in a network (like cities) using the minimum total cost of connections.

**Real-world analogy:**  
Like finding the cheapest way to connect all houses in a neighborhood with roads, ensuring every house is reachable but using the minimum total length of roads.

**Features:**
- **Kruskal's Algorithm:**
  - Edge-based approach: picks cheapest connections first
  - Uses Disjoint Set Union (DSU) to avoid creating loops
  - Sorts edges by weight
- **Prim's Algorithm:**
  - Vertex-based approach: grows tree from starting point
  - Uses priority queue for greedy selection
  - Adjacency list representation

**Algorithm Complexity:**
- Kruskal's: O(E log E)
- Prim's: O(E log V)

**Input Example:**
```
Enter number of vertices and edges: 4 5
Enter edges (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
```

**Usage:**
```bash
g++ program4.cpp -o program4
./program4
```

---

## Greedy Algorithms

### Problem 5: Fractional Knapsack Problem
**File:** [problem5.cpp](problem5.cpp)

**What it does:**  
Solves the problem of filling a knapsack (bag) with items to maximize value, where you can take fractions of items.

**Real-world analogy:**  
Like packing a suitcase with items of different values and weights. You can break items (like gold bars) into smaller pieces to maximize the total value while staying under the weight limit.

**Algorithm Used:** Greedy approach

**How it works:**
1. Calculate value-to-weight ratio for each item
2. Sort items by this ratio (highest first)
3. Pack items in order, taking fractions if needed

**Algorithm Complexity:**
- Time Complexity: O(n log n) - due to sorting
- Space Complexity: O(n)

**Input Example:**
```
Enter number of items: 3
Enter weight and value of each item:
10 60
20 100
30 120
Enter capacity of knapsack: 50
```

**Usage:**
```bash
g++ problem5.cpp -o problem5
./problem5
```

---

### Problem 6: Dijkstra's Shortest Path Algorithm
**File:** [problem6.cpp](problem6.cpp)

**What it does:**  
Finds the shortest path from one point to all other points in a weighted graph (network with distances).

**Real-world analogy:**  
Like Google Maps finding the shortest route from your location to all other destinations on the map.

**Algorithm Used:** Dijkstra's Algorithm

**How it works:**
1. Start from source vertex
2. Always pick the unvisited vertex with smallest distance
3. Update distances to neighbors
4. Repeat until all vertices are visited

**Algorithm Complexity:**
- Time Complexity: O((V + E) log V) with priority queue
- Space Complexity: O(V)

**Input Example:**
```
Enter number of vertices and edges: 5 7
Enter edges (u v w) where u->v has weight w:
0 1 10
0 4 5
1 2 1
1 4 2
2 3 4
3 2 6
4 1 3
Enter source vertex: 0
```

**Usage:**
```bash
g++ problem6.cpp -o problem6
./problem6
```

---

## Dynamic Programming

### Problem 7a: Floyd-Warshall Algorithm (All Pairs Shortest Path)
**File:** [problem7 a).cpp](problem7 a).cpp)

**What it does:**  
Finds the shortest paths between ALL pairs of vertices in a graph, showing intermediate steps.

**Real-world analogy:**  
Like creating a complete distance table between all cities, considering all possible routes through other cities.

**Algorithm Used:** Floyd-Warshall Algorithm

**How it works:**
1. Start with direct distances between vertices
2. For each vertex k, check if going through k gives a shorter path
3. Update distances if shorter path is found
4. Repeat for all vertices

**Key Concept:** Dynamic Programming - builds solution by solving smaller subproblems

**Algorithm Complexity:**
- Time Complexity: O(V³) - checks all combinations
- Space Complexity: O(V²) - stores distance matrix

**Input Example:**
```
Enter number of vertices: 4
Enter number of edges: 5
Enter edges in format (u v w):
0 1 5
0 3 10
1 2 3
2 3 1
3 1 2
Enter source vertex: 0
```

**Usage:**
```bash
g++ "problem7 a).cpp" -o problem7a
./problem7a
```

---

### Problem 7b: 0/1 Knapsack Problem (Dynamic Programming)
**File:** [problem 7 b).cpp](problem 7 b).cpp)

**What it does:**  
Solves the knapsack problem where you must take whole items (no fractions) to maximize value.

**Real-world analogy:**  
Like packing a backpack with whole items (you can't cut a laptop in half) to get maximum value while staying under weight limit.

**Algorithm Used:** Dynamic Programming

**How it works:**
1. Create a table where each cell represents "maximum value with i items and weight w"
2. For each item, decide: include it or exclude it
3. Choose the option that gives maximum value
4. Build up solution from smaller subproblems

**Key Difference from Problem 5:** Items cannot be fractioned; must take all or nothing

**Algorithm Complexity:**
- Time Complexity: O(n × W) where n = items, W = capacity
- Space Complexity: O(n × W)

**Input Example:**
```
Enter number of items: 4
Enter profit of items:
60 100 120 80
Enter weights of items:
10 20 30 25
Enter capacity of knapsack: 50
```

**Usage:**
```bash
g++ "problem 7 b).cpp" -o problem7b
./problem7b
```

---

### Problem 8a: N-Queens Problem
**File:** [problem8 a).cpp](problem8 a).cpp)

**What it does:**  
Solves the classic chess problem: place N queens on an N×N chessboard so no two queens attack each other.

**Real-world analogy:**  
Like placing security cameras in a grid where each camera can see its entire row, column, and diagonals - you need to position them so they don't overlap coverage.

**Algorithm Used:** Backtracking

**How it works:**
1. Place queens one row at a time
2. For each row, try placing queen in each column
3. Check if placement is safe (no conflicts)
4. If safe, move to next row
5. If stuck, backtrack and try different position

**Key Concept:** Backtracking - try a solution, if it doesn't work, undo and try another

**Algorithm Complexity:**
- Time Complexity: O(N!) - exponential, tries many combinations
- Space Complexity: O(N)

**Input Example:**
```
Enter number of queens: 4
```

**Output:** Shows all possible board configurations

**Usage:**
```bash
g++ "problem8 a).cpp" -o problem8a
./problem8a
```

---

### Problem 8b: Longest Common Subsequence (LCS)
**File:** [problem 8 b).cpp](problem 8 b).cpp)

**What it does:**  
Finds the longest sequence of characters that appear in the same order in two strings (but not necessarily consecutively).

**Real-world analogy:**  
Like finding common features between two DNA sequences, or detecting plagiarism by finding matching patterns in documents.

**Algorithm Used:** Dynamic Programming

**How it works:**
1. Create a table comparing each character of string 1 with string 2
2. If characters match, add 1 to diagonal value
3. If they don't match, take maximum from top or left
4. Trace back through table to reconstruct the LCS

**Example:**  
- String 1: "ABCDGH"
- String 2: "AEDFHR"
- LCS: "ADH" (appears in both in same order)

**Algorithm Complexity:**
- Time Complexity: O(m × n) where m, n are string lengths
- Space Complexity: O(m × n)

**Input Example:**
```
Enter first string: AGGTAB
Enter second string: GXTXAYB
```

**Output:** Shows DP matrix with arrows and the LCS

**Usage:**
```bash
g++ "problem 8 b).cpp" -o problem8b
./problem8b
```

---

## Advanced Algorithms

### Problem 9: 0/1 Knapsack (Backtracking)
**File:** [problem9.cpp](problem9.cpp)

**What it does:**  
Solves 0/1 knapsack using backtracking - tries all possible combinations to find the absolute best solution.

**Real-world analogy:**  
Like trying every possible combination of items in your backpack to find the one with maximum value, undoing choices that don't work.

**Algorithm Used:** Backtracking (Brute Force with Pruning)

**How it works:**
1. For each item, make two choices: include or exclude
2. Recursively try both options
3. Track the maximum profit found
4. Backtrack when weight exceeds capacity

**Difference from 7b:**  
- Problem 7b uses DP (efficient, stores results)
- Problem 9 uses backtracking (tries all combinations)

**Algorithm Complexity:**
- Time Complexity: O(2ⁿ) - exponential, tries all combinations
- Space Complexity: O(n) - recursion depth

**Input Example:**
```
Enter number of items: 4
Enter weights: 2 1 3 2
Enter values: 12 10 20 15
Enter knapsack capacity: 5
```

**Usage:**
```bash
g++ problem9.cpp -o problem9
./problem9
```

---

### Problem 10a: Traveling Salesman Problem (TSP) - Branch and Bound
**File:** [problem10 a).cpp](problem10 a).cpp)

**What it does:**  
Finds the shortest route that visits all cities exactly once and returns to the starting city.

**Real-world analogy:**  
Like a delivery driver finding the most efficient route to deliver packages to all addresses and return home.

**Algorithm Used:** Branch and Bound with Matrix Reduction

**How it works:**
1. Create cost matrix of distances between cities
2. Reduce matrix (subtract minimum from each row/column)
3. Use priority queue to explore most promising paths first
4. Prune paths that can't possibly be better than current best
5. Build complete tour and find minimum cost

**Key Concept:** Branch and Bound - systematically explore options while pruning branches that can't lead to better solutions

**Algorithm Complexity:**
- Time Complexity: O(n!) in worst case, but much better with pruning
- Space Complexity: O(n²)

**Input Example:**
```
Enter number of cities: 4
Enter cost matrix (use 'i' or 'I' for infinity):
i 10 15 20
10 i 35 25
15 35 i 30
20 25 30 i
```

**Output:** Shows optimal tour and its cost with intermediate steps

**Usage:**
```bash
g++ "problem10 a).cpp" -o problem10a
./problem10a
```

---

### Problem 10b: 0/1 Knapsack - Branch and Bound
**File:** [problem 10 b).cpp](problem 10 b).cpp)

**What it does:**  
Solves 0/1 knapsack more efficiently than backtracking by pruning unpromising branches early.

**Real-world analogy:**  
Like smartly packing a backpack by first considering the most valuable items per weight, and skipping combinations that clearly won't beat your current best.

**Algorithm Used:** Branch and Bound with Fractional Bound

**How it works:**
1. Sort items by value-to-weight ratio
2. Use priority queue to explore most promising solutions first
3. Calculate upper bound (fractional knapsack) for each node
4. Prune branches where upper bound ≤ current best
5. Track best solution found

**Key Advantage:** Much faster than pure backtracking for large inputs

**Algorithm Complexity:**
- Time Complexity: O(2ⁿ) worst case, but typically much better
- Space Complexity: O(n)

**Input Example:**
```
Enter number of items: 4
Enter weights of items (space separated): 2 1 3 2
Enter values of items (space separated): 12 10 20 15
Enter knapsack capacity: 5
```

**Output:** Shows maximum profit and which items to include

**Usage:**
```bash
g++ "problem 10 b).cpp" -o problem10b
./problem10b
```


## Key Concepts Explained

### 1. **Time Complexity**
Measures how execution time grows with input size:
- **O(1)**: Constant - always same time
- **O(log n)**: Logarithmic - very fast, doubles work for exponential input growth
- **O(n)**: Linear - time grows directly with input
- **O(n log n)**: Efficient sorting algorithms
- **O(n²)**: Quadratic - slow for large inputs
- **O(2ⁿ)**: Exponential - very slow, avoid for large n

### 2. **Space Complexity**
Measures how much memory an algorithm needs

### 3. **Algorithm Paradigms**

**Divide and Conquer** (Programs 3b, 2):
- Break problem into smaller pieces
- Solve each piece
- Combine solutions

**Greedy** (Problems 5, 6, Program 4):
- Make locally optimal choice at each step
- Hope global optimum emerges
- Fast but doesn't always give best answer

**Dynamic Programming** (Problems 7a, 7b, 8b):
- Break into overlapping subproblems
- Store solutions to avoid recalculation
- Build up to final solution

**Backtracking** (Problems 8a, 9):
- Try building solution incrementally
- Undo (backtrack) when stuck
- Explore all possibilities

**Branch and Bound** (Problems 10a, 10b):
- Like backtracking but smarter
- Prune branches that can't improve solution
- Uses bounds to avoid unnecessary work

### 4. **Data Structures Used**

- **Arrays**: Linear collection of elements
- **Graphs**: Nodes connected by edges
- **Priority Queue**: Always gives smallest/largest element
- **Stack**: Last-In-First-Out (LIFO)
- **Queue**: First-In-First-Out (FIFO)
- **Disjoint Set (Union-Find)**: Tracks separate groups

---

## Learning Path

**Beginners Start Here:**
1. Program 1 (Binary Search) - Learn recursion
2. Program 2 (QuickSort) - Understand sorting
3. Problem 5 (Fractional Knapsack) - First greedy algorithm

**Intermediate:**
4. Program 3a (BFS/DFS) - Graph basics
5. Program 4 (MST) - Advanced graph algorithms
6. Problem 7b (0/1 Knapsack DP) - Dynamic programming intro

**Advanced:**
7. Problem 8a (N-Queens) - Backtracking
8. Problem 10a (TSP) - Optimization
9. Problem 10b (Knapsack B&B) - Advanced pruning

---

## Common Applications

- **Search Algorithms**: Databases, file systems
- **Sorting**: Data organization, preprocessing
- **Graph Algorithms**: Maps, social networks, network routing
- **Dynamic Programming**: Sequence alignment (DNA), resource allocation
- **Greedy Algorithms**: Scheduling, compression
- **Optimization**: Logistics, planning, resource management

---

## Notes

- All programs include performance measurement using `std::chrono`
- Random number generation is seeded for reproducible results
- Memory management is handled properly in dynamic allocation scenarios
- Programs follow standard C++ practices and conventions
- Comments and output help understand algorithm execution

## Tips for Understanding

1. **Run with small inputs first** - easier to trace execution
2. **Draw diagrams** - visualize what's happening
3. **Modify and experiment** - change inputs, add print statements
4. **Compare outputs** - see how different algorithms solve same problem
5. **Time different input sizes** - observe complexity in practice

---

## Contributing

Feel free to suggest improvements or report issues!

## License

Educational purposes - free to use and modify.
