#include <stdio.h>
#include <stdlib.h>

// Graph node structure
typedef struct GraphNode {
    int vertex;
    struct GraphNode* next;
} GraphNode;

// Graph structure
typedef struct {
    int numVertices;
    GraphNode** adjList;
} Graph;

// Function to create a new graph node
GraphNode* createNode(int vertex) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (GraphNode**)malloc(sizeof(GraphNode*) * numVertices);
    for (int i = 0; i < numVertices; i++)
        graph->adjList[i] = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to perform breadth-first search traversal of the graph
void BFS(Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    
    // Create a queue for BFS
    int queue[graph->numVertices];
    int front = 0, rear = 0;
    
    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    
    while (front != rear) {
        // Dequeue a vertex from the queue and print it
        int vertex = queue[front++];
        printf("%d ", vertex);
        
        // Get all adjacent vertices of the dequeued vertex
        GraphNode* currentNode = graph->adjList[vertex];
        while (currentNode != NULL) {
            int adjVertex = currentNode->vertex;
            
            // If the adjacent vertex is not visited, mark it as visited and enqueue it
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            
            currentNode = currentNode->next;
        }
    }
    
    free(visited);
}

// Function to perform depth-first search traversal of the graph
void DFSUtil(Graph* graph, int vertex, int* visited) {
    // Mark the current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    // Recur for all the adjacent vertices of the current vertex
    GraphNode* currentNode = graph->adjList[vertex];
    while (currentNode != NULL) {
        int adjVertex = currentNode->vertex;
        if (!visited[adjVertex])
            DFSUtil(graph, adjVertex, visited);
        currentNode = currentNode->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    DFSUtil(graph, startVertex, visited);
    free(visited);
}

// Main function
int main() {
    int numVertices = 6;
    Graph* graph = createGraph(numVertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    printf("BFS traversal: ");
    BFS(graph, 0);
    printf("\n");
    
    printf("DFS traversal: ");
    DFS(graph, 0);
    printf("\n");
    
    return 0;
}
