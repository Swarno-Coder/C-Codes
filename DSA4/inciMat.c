#include <stdio.h>

#define MAX_VERTICES 100

void createIncidenceMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int edges, int directed) {
    int i, j, v1, v2, weight;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < edges; j++) {
            graph[i][j] = 0;
        }
    }
    for (i = 0; i < edges; i++) {
        printf("Enter the vertices and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &v1, &v2, &weight);
        printf("%d %d %d", v1, v2, weight);
        graph[v1 - 1][i] = weight;
        if (!directed) {
            graph[v2 - 1][i] = weight;
        }
    }
}

void findVerticesWithEvenDegree(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int edges, int directed) {
    int i, j, degree, count;
    for (i = 0; i < vertices; i++) {
        degree = 0;
        count = 0;
        for (j = 0; j < edges; j++) {
            if (graph[i][j] != 0) {
                count++;
                if (!directed) {
                    degree += graph[i][j];
                } else {
                    if (graph[i][j] > 0) {
                        degree += graph[i][j];
                    }
                    if (graph[i][j] < 0) {
                        degree -= graph[i][j];
                    }
                }
            }
        }
        if (count > 0 && degree % 2 == 0) {
            printf("Vertex %d has even degree.\n", i + 1);
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices, edges, directed;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    printf("Is the graph directed? (0 for undirected, 1 for directed): ");
    scanf("%d", &directed);

    createIncidenceMatrix(graph, vertices, edges, directed);
    findVerticesWithEvenDegree(graph, vertices, edges, directed);

    return 0;
}
