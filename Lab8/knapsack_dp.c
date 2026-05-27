#include <stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int n,W,i,w;
    printf("Enter number of items:");
    scanf("%d",&n);
    int weight[n + 1],profit[n + 1];
    printf("Enter weights of items:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&weight[i]);
    printf("Enter profits of items:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&profit[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d",&W);
    int dp[n + 1][W + 1];
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=W;w++)
        {
            if(i==0||w==0)
                dp[i][w]=0;
            else if(weight[i]<=w)
                dp[i][w]=max(profit[i]+dp[i-1][w-weight[i]],dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    printf("\nMaximum profit=%d\n",dp[n][W]);
    printf("Selected items are:\n");
    w=W;
    for(i=n;i>0 && w>0;i--)
    {
        if(dp[i][w]!=dp[i-1][w])
        {
            printf("Item %d (Weight=%d, Profit=%d)\n",i, weight[i], profit[i]);
            w=w-weight[i];
        }
    }
    return 0;
}
