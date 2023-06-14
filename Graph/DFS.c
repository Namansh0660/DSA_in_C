#include <stdio.h>
#include <stdbool.h>
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
void addEdge(Graph *graph, int src, int dest) 
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}
void dfsRecursive(Graph *graph, int startNode, bool visited[]) 
{
    visited[startNode] = true;
    printf("Visited: %d\n", startNode);
    for (int i = 0; i < graph->numNodes; i++) 
    {
        if (graph->adjMatrix[startNode][i] == 1 && !visited[i]) 
        {
            dfsRecursive(graph, i, visited);
        }
    }
}
void dfs(Graph *graph, int startNode) 
{
    bool visited[MAX_NODES] = {false};
    dfsRecursive(graph, startNode, visited);
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
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);
    printf("DFS traversal:\n");
    dfs(&graph, startNode);
    return 0;
}
