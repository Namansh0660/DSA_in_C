#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_NODES 100
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
void addEdge(Graph *graph, int src, int dest, int weight) 
{
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}
int minDistance(int dist[], bool visited[], int numNodes) 
{
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < numNodes; i++) 
    {
        if (!visited[i] && dist[i] < min) 
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void printPath(int parent[], int destination) 
{
    if (parent[destination] == -1) 
    {
        printf("%d ", destination);
        return;
    }
    printPath(parent, parent[destination]);
    printf("%d ", destination);
}
void dijkstra(Graph *graph, int source) 
{
    int dist[MAX_NODES];
    bool visited[MAX_NODES];
    int parent[MAX_NODES];
    for (int i = 0; i < graph->numNodes; i++) 
    {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[source] = 0;
    for (int count = 0; count < graph->numNodes - 1; count++) 
    {
        int u = minDistance(dist, visited, graph->numNodes);
        visited[u] = true;
        for (int v = 0; v < graph->numNodes; v++) 
        {
            if (!visited[v] && graph->adjMatrix[u][v] != 0 && dist[u] + graph->adjMatrix[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
    printf("Shortest paths from source node %d:\n", source);
    for (int i = 0; i < graph->numNodes; i++) 
    {
        if (i != source) 
        {
            printf("Path to node %d: ", i);
            printPath(parent, i);
            printf("\nDistance: %d\n", dist[i]);
        }
    }
}
int main() 
{
    Graph graph;
    int numNodes, numEdges, sourceNode;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    initGraph(&graph, numNodes);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (source node, destination node, and weight):\n");
    for (int i = 0; i < numEdges; i++) 
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }
    printf("Enter the source node for shortest paths: ");
    scanf("%d", &sourceNode);
    dijkstra(&graph, sourceNode);
    return 0;
}