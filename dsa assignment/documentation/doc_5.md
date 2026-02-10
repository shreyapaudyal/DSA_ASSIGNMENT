# Undirected Graph - BFS and DFS Traversal

## Data Structure Definitions
```c
typedef struct {
    int items[MAX];  // Queue elements
    int front, rear; // Queue indices
} Queue;

typedef struct {
    int V;              // Number of vertices
    int adj[MAX][MAX];  // Adjacency matrix
} Graph;
```

Graph uses adjacency matrix where `adj[i][j] = 1` indicates edge between i and j.

## Functions Implemented

**Queue Operations:**
- `createQueue()` - Initializes empty queue
- `isEmpty(Queue *q)` - Checks if queue empty
- `enqueue(Queue *q, int value)` - Adds element to rear
- `dequeue(Queue *q)` - Removes and returns front element

**Graph Operations:**
- `createGraph(int V)` - Creates graph with V vertices, initializes matrix to 0
- `addEdge(Graph *g, int u, int v)` - Adds undirected edge: sets adj[u][v] and adj[v][u] to 1
- `DFSUtil(Graph *g, int v, bool visited[])` - Recursive DFS helper: mark visited, print, recurse on unvisited neighbors
- `DFS(Graph *g, int start)` - Initiates DFS traversal from start vertex
- `BFS(Graph *g, int start)` - Level-by-level traversal using queue
- `displayGraph(Graph *g)` - Prints adjacency matrix

## Main Method Organization

1. Create graph with 6 vertices
2. Add edges: (0,1), (0,2), (1,3), (1,4), (2,4), (3,5), (4,5)
3. Display adjacency matrix
4. Perform BFS from vertex 0
5. Perform DFS from vertex 0

## Sample Output
```
Adjacency Matrix:
   0 1 2 3 4 5 
0: 0 1 1 0 0 0 
1: 1 0 0 1 1 0 
2: 1 0 0 0 1 0 
3: 0 1 0 0 0 1 
4: 0 1 1 0 0 1 
5: 0 0 0 1 1 0 

BFS from 0: 0 1 2 3 4 5 
DFS from 0: 0 1 3 5 4 2 
```

**BFS:** Explores level by level (uses queue)  
**DFS:** Explores depth first (uses recursion/stack)