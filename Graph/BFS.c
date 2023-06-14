#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
typedef struct
{
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;
typedef struct 
{
    int adjMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
} Graph;
void initGraph(Graph *graph, int numNodes) 
{
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) 
    {
        for (int j = 0; j < numNodes; j++) 
        {
            graph->adjMatrix[i][j] = 0;
        }
    }
}
void addEdge(Graph *graph, int src, int dest) 
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
void bfs(Graph *graph, int startNode, bool visited[]) 
{
    Queue queue;
    queue.front = 0;
    queue.rear = -1;
    visited[startNode] = true;
    printf("Visited: %d\n", startNode);
    queue.items[++queue.rear] = startNode;
    while (queue.front <= queue.rear) 
    {
        int currentNode = queue.items[queue.front++];
        for (int i = 0; i < graph->numNodes; i++) 
        {
            if (graph->adjMatrix[currentNode][i] == 1 && !visited[i]) 
            {
                queue.items[++queue.rear] = i;
                visited[i] = true;
                printf("Visited: %d\n", i);
            }
        }
    }
}
int main() 
{
    Graph graph;
    int numNodes, numEdges, startNode;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    initGraph(&graph, numNodes);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (source node and destination node):\n");
    for (int i = 0; i < numEdges; i++) 
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    bool visited[MAX_NODES] = { false };
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);
    printf("BFS traversal:\n");
    bfs(&graph, startNode, visited);
    return 0;
}
