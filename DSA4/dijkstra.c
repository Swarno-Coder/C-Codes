/*#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define INF 99999

void dijkstra(int graph[MAX_NODES][MAX_NODES], int numNodes, int sourceNode, int targetNode) {
    int distance[MAX_NODES];    // Shortest distance from source to each node
    bool visited[MAX_NODES];    // Track visited nodes
    int i, j, minDistance, nextNode;
    
    // Initialize distance and visited arrays
    for (i = 0; i < numNodes; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    
    distance[sourceNode] = 0;   // Distance from source to itself is 0
    
    for (i = 0; i < numNodes - 1; i++) {
        minDistance = INF;
        
        // Find the node with the minimum distance
        for (j = 0; j < numNodes; j++) {
            if (!visited[j] && distance[j] <= minDistance) {
                minDistance = distance[j];
                nextNode = j;
            }
        }
        
        visited[nextNode] = true;
        
        // Update the distance of the adjacent nodes
        for (j = 0; j < numNodes; j++) {
            if (!visited[j] && graph[nextNode][j] && distance[nextNode] != INF &&
                distance[nextNode] + graph[nextNode][j] < distance[j]) {
                distance[j] = distance[nextNode] + graph[nextNode][j];
            }
        }
    }
    
    // Print the shortest distance to the target node
    printf("Shortest distance from node %d to node %d is: %d\n", sourceNode, targetNode, distance[targetNode]);
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    int numNodes, sourceNode, targetNode;
    int i, j;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the source node: ");
    scanf("%d", &sourceNode);
    
    printf("Enter the target node: ");
    scanf("%d", &targetNode);
    
    dijkstra(graph, numNodes, sourceNode, targetNode);
    
    return 0;
}
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
#define INF 99999

int minDistance(int distance[], bool visited[], int numNodes) {
    int min = INF, minIndex;
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int numNodes, int sourceNode, int targetNode) {
    int distance[MAX_NODES];
    int parent[MAX_NODES]; // Keep track of the shortest path
    bool visited[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[sourceNode] = 0;
    parent[sourceNode] = -1; // Set the parent of source node as -1

    for (int count = 0; count < numNodes - 1; count++) {
        int u = minDistance(distance, visited, numNodes);
        visited[u] = true;

        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the shortest distance and path
    printf("Shortest distance from node %d to node %d is: %d\n", sourceNode, targetNode, distance[targetNode]);
    
    printf("Shortest path: ");
    int current = targetNode;
    printf("%d ", current);
    while (parent[current] != -1) {
        printf("<- %d ", parent[current]);
        current = parent[current];
    }
    printf("\n");
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    int numNodes, sourceNode, targetNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &sourceNode);

    printf("Enter the target node: ");
    scanf("%d", &targetNode);

    dijkstra(graph, numNodes, sourceNode, targetNode);

    return 0;
}
