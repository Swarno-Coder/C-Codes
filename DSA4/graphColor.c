#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int n;
int G[MAX][MAX];
int m;
int color[MAX];

void printSolution()
{
    printf("Minimum number of colors required: %d\n", m);
    printf("Colors assigned to vertices: ");
    for (int i = 0; i < n; i++)
        printf("%d ", color[i]);
    printf("\n");
}

bool isSafe(int v, int c)
{
    for (int i = 0; i < n; i++)
        if (G[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(int v)
{
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (graphColoringUtil(v + 1) == true)
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(int m)
{
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (graphColoringUtil(0) == false)
        return false;

    printSolution();
    return true;
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (!graphColoring(m))
        printf("Solution does not exist");

    return 0;
}
