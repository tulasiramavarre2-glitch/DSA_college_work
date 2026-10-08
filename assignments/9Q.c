#include<stdio.h>
int graph[20][20],visited[20],n;
void dfs(int v)
{
int i;
visited[v]=1;
printf("%d ",v);
for(i=0;i<n;i++)
{
if(graph[v][i]==1&&visited[i]==0)
{
dfs(i);
}
}
}
int main()
{
int i,j,start;
printf("Enter number of vertices: ");
scanf("%d",&n);
printf("Enter adjacency matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&graph[i][j]);
}
}
printf("Enter starting vertex: ");
scanf("%d",&start);
for(i=0;i<n;i++)
{
visited[i]=0;
}
printf("DFS Traversal: ");
dfs(start);
printf("\n");
return 0;
}