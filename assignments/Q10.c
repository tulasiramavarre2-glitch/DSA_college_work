#include<stdio.h>
#define INF 99999
int main()
{
int n,i,j,source,min,u;
int cost[20][20],dist[20],visited[20];
printf("Enter number of vertices: ");
scanf("%d",&n);
printf("Enter weighted adjacency matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0&&i!=j)
cost[i][j]=INF;
}
}
printf("Enter source vertex: ");
scanf("%d",&source);
for(i=0;i<n;i++)
{
dist[i]=cost[source][i];
visited[i]=0;
}
dist[source]=0;
visited[source]=1;
for(i=1;i<n;i++)
{
min=INF;
u=-1;
for(j=0;j<n;j++)
{
if(visited[j]==0&&dist[j]<min)
{
min=dist[j];
u=j;
}
}
if(u==-1)
break;
visited[u]=1;
for(j=0;j<n;j++)
{
if(visited[j]==0&&cost[u][j]!=INF&&dist[u]+cost[u][j]<dist[j])
dist[j]=dist[u]+cost[u][j];
}
}
printf("\nShortest distances from vertex %d:\n",source);
for(i=0;i<n;i++)
{
if(dist[i]==INF)
printf("Destination %d = INF\n",i);
else
printf("Destination %d = %d\n",i,dist[i]);
}
return 0;
}