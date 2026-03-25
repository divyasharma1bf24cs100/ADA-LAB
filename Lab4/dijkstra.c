#include<stdio.h>
#include<stdlib.h>
void dijkstra(int n,int cost[10][10],int src,int dist[10]){
    int vis[10],i,v,count=1,min;
    for(i=1;i<=n;i++){
        vis[i]=0;
        dist[i]=cost[src][i];
    }
    dist[src]=0;
    vis[src]=1;
    while(count<=n){
        min=999;
        for(i=1;i<=n;i++){
            if(dist[i]<min && vis[i]==0){
                min=dist[i];
                v=i;
            }
        }
        vis[v]=1;
        count++;
        for(i=1;i<=n;i++){
            if(dist[i]>dist[v]+cost[v][i])
                dist[i]=dist[v]+cost[v][i];
        }
    }
}
int main(){
    int n,i,j,src,cost[10][10],dist[10];
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter Matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){cost[i][j]=999;}
        }
    }
    printf("Enter Source:");
    scanf("%d",&src);
    dijkstra(n,cost,src,dist);
    printf("Shortest path from %d is \n",src);
    for(i=1;i<=n;i++)
        if(src!=i)
            printf("%d->%d=%d ",src,i,dist[i]);
    return 0;
}

