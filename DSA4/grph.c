#include<stdio.h>
#include<conio.h>

void adj_mat(int n){
    int adj_mat[n][n];
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            printf("\n Is vertex %d-%d is connected?--> ",i+1,j+1);
            c = getche();
            if (c=='y'||c=='Y') adj_mat[i][j]=1;
            else if (c == 'n' || c == 'N') adj_mat[i][j] = 0;
        }
    }
    printf("\n\n Adjacency matrix of the graph is -->");
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf(" %d",adj_mat[i][j]);
        }
    }
}

int main(void){
    int n;
    printf("\n Enter the number of vertices are in the graph: ");
    scanf("%d",&n);
    adj_mat(n);
    return 0;
}
