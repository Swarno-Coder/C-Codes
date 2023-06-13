#include<stdio.h>
#define MAX 100
int main(){
    int top=-1;
    int no_of_vertex=6;
    int starting_vertex=1;
    int stack[MAX];
    int visited[6]={0};
    int adj_mat[6][6]={
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };
    visited[starting_vertex]=1;
    stack[++top]=starting_vertex;
    printf("DFS Spanning Tree Traversal: ");
    while(top!=-1){
        int current_vertex=stack[top--];
        printf("%d ",current_vertex+1);
        for (int i = 0; i<no_of_vertex; i++)
        {
           
            if(!visited[i] && adj_mat[current_vertex][i]){
                stack[++top]=i;
                visited[i]=1;
                break;
            }
        }
    }
    return 0;
}