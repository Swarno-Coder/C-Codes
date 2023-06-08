#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void bfs(int adj_matrix[][MAX_VERTICES], int num_vertices, int start_vertex, int traversal_list[], int selected_edges[][2], int* num_edges, int spanning_tree[][MAX_VERTICES])
{
    // Initialize visited array to all false
    bool visited[MAX_VERTICES] = { false };
    
    // Initialize queue for BFS traversal
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    // Enqueue start vertex and mark as visited
    queue[rear++] = start_vertex;
    visited[start_vertex] = true;
    
    // Loop until queue is empty
    while (front != rear)
    {
        // Dequeue vertex from queue and add to traversal list
        int current_vertex = queue[front++];
        traversal_list[front - 1] = current_vertex;
        
        // Loop through adjacent vertices of current vertex
        for (int i = 0; i < num_vertices; i++)
        {
            if (adj_matrix[current_vertex][i] == 1) // i is adjacent to current_vertex
            {
                if (!visited[i]) // i has not been visited yet
                {
                    // Enqueue i, mark as visited, and add edge to selected edges
                    queue[rear++] = i;
                    visited[i] = true;
                    selected_edges[*num_edges][0] = current_vertex;
                    selected_edges[*num_edges][1] = i;
                    (*num_edges)++;
                    
                    // Add edge to spanning tree
                    spanning_tree[current_vertex][i] = 1;
                    spanning_tree[i][current_vertex] = 1;
                }
            }
        }
    }
}

int main()
{
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices, start_vertex;
    int traversal_list[MAX_VERTICES];
    int selected_edges[MAX_VERTICES - 1][2]; // Maximum number of edges in spanning tree is num_vertices - 1
    int num_edges = 0;
    int spanning_tree[MAX_VERTICES][MAX_VERTICES] = { {0} }; // Initialize to all zeros
    
    // Read input from user
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);
    
    // Perform BFS
    bfs(adj_matrix, num_vertices, start_vertex, traversal_list, selected_edges, &num_edges, spanning_tree);
    
    // Print results
    printf("BFS Traversal List: ");
    for (int i = 0; i < num_vertices; i++)
    {
        printf("%d ", traversal_list[i]);
    }
    printf("\nSelected Edges:\n");
    for (int i = 0; i < num_edges; i++)
    {
        printf("(%d, %d)\n", selected_edges[i][0], selected_edges[i][1]);
    }
    printf("Adjacency Matrix of Spanning Tree:\n");
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0    ; j < num_vertices; j++)
    {
        printf("%d ", spanning_tree[i][j]);
    }
    printf("\n");
}

return 0;
}
