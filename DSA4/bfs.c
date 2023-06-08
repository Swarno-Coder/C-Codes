#include<stdio.h>
#include<conio.h>
void bfs(int a[20][20],int n,int source)
{
    int q[20],visited[20],i,j,f=0,r=-1;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    visited[source]=1;
    q[++r]=source;
    while(f<=r)
    {
        i=q[f++];
        for(j=1;j<=n;j++)
        {
            if(a[i][j] && !visited[j])
            {
                visited[j]=1;
                q[++r]=j;
            }
        }
    }
    printf("The BFS Traversal is...\n");
    for(i=1;i<=n;i++)
    {
        if(visited[i])
        {
            printf("%d\t",i);
        }
        else
        {
            printf("\nBFS is not possible. Not all nodes are reachable.");
            break;
        }
    }
}
void main()
{
    int n,a[20][20],i,j,source;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the source vertex:\n");
    scanf("%d",&source);
    bfs(a,n,source);
}