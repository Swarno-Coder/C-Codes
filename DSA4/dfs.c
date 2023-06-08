#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES] = {0};
int selected_edges[MAX_VERTICES][2];
int num_selected_edges = 0;
int spanning_tree[MAX_VERTICES][MAX_VERTICES] = {0};

void dfs(int v, int num_vertices) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < num_vertices; i++) {
        if (adj_matrix[v][i] && !visited[i]) {
            selected_edges[num_selected_edges][0] = v;
            selected_edges[num_selected_edges][1] = i;
            num_selected_edges++;
            spanning_tree[v][i] = 1;
            spanning_tree[i][v] = 1;
            dfs(i, num_vertices);
        }
    }
}

int main() {
    int num_vertices, start_vertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);
    printf("DFS traversal: ");
    dfs(start_vertex, num_vertices);
    printf("\nSelected edges:\n");
    for (int i = 0; i < num_selected_edges; i++) {
        printf("(%d, %d)\n", selected_edges[i][0], selected_edges[i][1]);
    }
    printf("Adjacency matrix of spanning tree:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", spanning_tree[i][j]);
        }
        printf("\n");
    }
    return 0;
}
