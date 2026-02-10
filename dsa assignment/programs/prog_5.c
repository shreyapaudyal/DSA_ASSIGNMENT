#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

bool isEmpty(Queue *q) { return q->rear == -1; }

void enqueue(Queue *q, int value) {
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    int item = q->items[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

typedef struct {
    int V;
    int adj[MAX][MAX];
} Graph;

Graph* createGraph(int V) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g->adj[i][j] = 0;
    return g;
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = g->adj[v][u] = 1;
}

void DFSUtil(Graph *g, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);
    
    for (int i = 0; i < g->V; i++)
        if (g->adj[v][i] && !visited[i])
            DFSUtil(g, i, visited);
}

void DFS(Graph *g, int start) {
    bool visited[MAX] = {false};
    printf("DFS from %d: ", start);
    DFSUtil(g, start, visited);
    printf("\n");
}

void BFS(Graph *g, int start) {
    bool visited[MAX] = {false};
    Queue *q = createQueue();
    
    visited[start] = true;
    enqueue(q, start);
    
    printf("BFS from %d: ", start);
    
    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);
        
        for (int i = 0; i < g->V; i++) {
            if (g->adj[v][i] && !visited[i]) {
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < g->V; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < g->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->V; j++)
            printf("%d ", g->adj[i][j]);
        printf("\n");
    }
}

int main() {
    Graph *g = createGraph(6);
    
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4);
    addEdge(g, 3, 5);
    addEdge(g, 4, 5);
    
    displayGraph(g);
    printf("\n");
    
    BFS(g, 0);
    DFS(g, 0);
    
    return 0;
}