#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int adjMatrix[100][100];  // Adjacency matrix
int visited[100];         // Visited array
int parent[100];          // Parent of each vertex in spanning tree

int traversalList[100];   // Traversal list
int selectedEdges[100][2]; // Selected edges in BFS order
int edgeCount = 0;        // Number of selected edges

typedef struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1)
        printf("Queue overflow\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

void bfs(int start, int numVertices) {
    Queue* q = createQueue();
    visited[start] = 1;
    enqueue(q, start);
    traversalList[0] = start;
    int i, currentVertex;
    while (!isEmpty(q)) {
        currentVertex = dequeue(q);
        for (i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                parent[i] = currentVertex;
                enqueue(q, i);
                traversalList[q->rear] = i;
                selectedEdges[edgeCount][0] = currentVertex;
                selectedEdges[edgeCount][1] = i;
                edgeCount++;
            }
        }
    }
}

void printTraversal(int numVertices) {
    printf("Traversal list: ");
    int i;
    for (i = 0; i < numVertices; i++) {
        printf("%d ", traversalList[i]);
    }
    printf("\n");
}

void printSelectedEdges(int numVertices) {
    int i, j;
    printf("Selected edges: ");
    for (i = 0; i < numVertices; i++) {
        if (parent[i] != -1) {
            printf("(%d,%d) ", parent[i], i);
        }
    }
    printf("\n");
}


void printAdjMatrix(int numVertices) {
    printf("Adjacency matrix of spanning tree: \n");
    int i, j;
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (parent[j] == i) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int numVertices, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d",&numVertices);
for (int i = 0; i < numVertices; i++) {
    visited[i] = 0;
    parent[i] = -1;
}
printf("Enter the adjacency matrix: \n");
for (int i = 0; i < numVertices; i++) {
    for (int j = 0; j < numVertices; j++) {
        scanf("%d", &adjMatrix[i][j]);
    }
}
printf("You Entered:");
for (int i = 0; i < numVertices; i++) {
    printf("\n");
    for (int j = 0; j < numVertices; j++)
        printf("%d ", adjMatrix[i][j]);
}

printf("\nEnter the starting vertex: ");
scanf("%d", &startVertex);
bfs(startVertex, numVertices);
printTraversal(numVertices);
printSelectedEdges(numVertices);
printAdjMatrix(numVertices);
return 0;
}
