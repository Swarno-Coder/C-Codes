#include <stdio.h>

#define MAX_VERTICES 100

int incidenceMatrix[MAX_VERTICES][MAX_VERTICES];
char a[]={'A','B','C','D','E'};


void createGraph(int numVertices, int numEdges) {
    char response;
    printf("Enter d if vertex is destination of a directed graph\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numEdges; j++) {
            printf(" Is vertex %c is end point of edge %d?(y/n):",a[i],j+1);
            fflush(stdin);
            scanf("%c",&response);
            if(response =='y' || response =='Y')
                incidenceMatrix[i][j] = 1;
            else if(response =='D' || response =='d')
                incidenceMatrix[i][j] = -1;
            else 
                incidenceMatrix[i][j] = 0;
        }
    }
}
void printIncidenceMatrix(int numVertices,int numEdges){
    for(int i=0;i<numVertices;++i){
        for(int j=0;j<numEdges;++j){ printf("%d ",incidenceMatrix[i][j]); }
        printf("\n");
    }
}
void findEvenDegreeEdge(int numVertices,int numEdges){
    int degree=0;
    printf("Vertices of even degree is/are: ");
    for(int i=0; i<numVertices; ++i){
        for(int j=0; j<numEdges; ++j){
            if(incidenceMatrix[i][j]==1){
                degree++;
            }
        }
        if(degree%2==0 &&degree>0){
            printf("%d, ",i);
        }
        degree=0;
        
    }
}
int main() {
    int numVertices,numEdges;
    printf("Enter the number of vertices & edges: ");
    scanf("%d%d", &numVertices, &numEdges);
    createGraph(numVertices,numEdges);
    printIncidenceMatrix(numVertices,numEdges);
    findEvenDegreeEdge(numVertices,numEdges);
    return 0;
}
