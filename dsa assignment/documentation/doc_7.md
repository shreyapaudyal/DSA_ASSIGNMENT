# Dijkstra's Shortest Path Algorithm

## Data Structure
Adjacency matrix `graph[MAX][MAX]` where `graph[i][j]` is the weight of edge from i to j (0 = no edge).

## Functions

**`findMin(int dist[], int visited[], int n)`** - Returns unvisited vertex with minimum distance.

**`dijkstra(int graph[MAX][MAX], int n, int start)`** - Finds shortest paths from start vertex to all others using greedy approach.

## Main Method
1. Define 7-vertex weighted graph
2. Display adjacency matrix
3. Run Dijkstra from vertex 0
4. Print shortest distances

## Sample Output
```
Vertex	Distance from 0
0	0
1	2
2	6
3	7
4	17
5	19
6	19
```

## Complexity
Time: O(V²), Space: O(V)