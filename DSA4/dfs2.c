#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int n, int v, int* traversalList, int* selectedEdges, int* adjacencyMatrix) {
    int i, j;
    visited[v] = 1;
    traversalList[*traversalList] = v;
    *traversalList += 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] != 0) {
            if (!visited[i]) {
                selectedEdges[*selectedEdges] = graph[v][i];
                *selectedEdges += 1;

                adjacencyMatrix[v * n + i] = graph[v][i];
                adjacencyMatrix[i * n + v] = graph[v][i];

                dfs(graph, visited, n, i, traversalList, selectedEdges, adjacencyMatrix);
            }
            else {
                adjacencyMatrix[v * n + i] = graph[v][i];
                adjacencyMatrix[i * n + v] = graph[v][i];
            }
        }
    }
}

void dfsTraversal(int graph[MAX_VERTICES][MAX_VERTICES], int n, int startVertex, int* traversalList, int* selectedEdges, int* adjacencyMatrix) {
    int visited[MAX_VERTICES] = {0};
    *traversalList = 0;
    *selectedEdges = 0;
    int i;

    dfs(graph, visited, n, startVertex, traversalList, selectedEdges, adjacencyMatrix);

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, visited, n, i, traversalList, selectedEdges, adjacencyMatrix);
        }
    }
}

int main() {
    int n, graph[MAX_VERTICES][MAX_VERTICES], startVertex, traversalList[MAX_VERTICES], selectedEdges[MAX_VERTICES], adjacencyMatrix[MAX_VERTICES * MAX_VERTICES];
    int i, j, k = 0;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfsTraversal(graph, n, startVertex, &traversalList[0], &selectedEdges[0], &adjacencyMatrix[0]);

    printf("Traversal List: ");
    for (i = 0; i < n; i++) {
        printf("%d ", traversalList[i]);
    }
    printf("\n");

    printf("Selected Edges: ");
    for (i = 0; i < n - 1; i++) {
        printf("(%d,%d) ", traversalList[i], traversalList[i + 1]);
    }
    printf("\n");

    printf("Adjacency Matrix of Spanning Tree:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adjacencyMatrix[k++]);
        }
        printf("\n");
    }

    return 0;
}
