#include <stdio.h>

#define MAX_SIZE 100

void graphColoring(int, int [MAX_SIZE][MAX_SIZE], int []);

int main() {
    int n, adjMatrix[MAX_SIZE][MAX_SIZE], colors[MAX_SIZE];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    graphColoring(n, adjMatrix, colors);

    printf("Minimum color required: %d\n", colors[n-1]);
    printf("Colors used: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");

    return 0;
}

void graphColoring(int n, int adjMatrix[MAX_SIZE][MAX_SIZE], int colors[]) {
    int available[n];
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
        available[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j]) {
                if (colors[j] != 0) {
                    available[colors[j] - 1] = 0;
                }
            }
        }

        int c;
        for (c = 0; c < n; c++) {
            if (available[c]) {
                break;
            }
        }

        colors[i] = c + 1;

        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j]) {
                if (colors[j] != 0) {
                    available[colors[j] - 1] = 1;
                }
            }
        }
    }
}
