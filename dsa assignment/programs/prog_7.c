#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

// Find the vertex with minimum distance that hasn't been visited yet
int findMin(int dist[], int visited[], int n) {
    int min = INF;
    int minIndex = -1;
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];      // shortest distance from start to each vertex
    int visited[MAX];   // track visited vertices
    int parent[MAX];    // track path
    
    // Initialize everything
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    
    dist[start] = 0;  // distance to starting vertex is 0
    
    // Main loop - find shortest path to all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick minimum distance vertex from unvisited vertices
        int u = findMin(dist, visited, n);
        
        if (u == -1) break;  // no more reachable vertices
        
        visited[u] = 1;  // mark as visited
        
        // Update distances of neighbors
        for (int v = 0; v < n; v++) {
            // Check if there's an edge and if we found a shorter path
            if (visited[v] == 0 && graph[u][v] != 0 && 
                dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    // Print results
    printf("\nShortest Distances from vertex %d:\n", start);
    printf("Vertex\tDistance\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int n = 7;  // number of vertices
    
    // The graph as adjacency matrix (0 means no edge)
    int graph[MAX][MAX] = {
        {0, 2, 6, 0, 0, 0, 0},
        {2, 0, 0, 5, 0, 0, 0},
        {6, 0, 0, 8, 0, 0, 0},
        {0, 5, 8, 0, 10, 15, 0},
        {0, 0, 0, 10, 0, 6, 2},
        {0, 0, 0, 15, 6, 0, 6},
        {0, 0, 0, 0, 2, 6, 0}
    };
    
    printf("Graph Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    dijkstra(graph, n, 0);  // find shortest paths from vertex 0
    
    return 0;
}