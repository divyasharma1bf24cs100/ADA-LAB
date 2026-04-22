#include<stdio.h>
struct Obj{
    int weight;
    int profit;
    float ratio;
    int index;
};
void sort(struct Obj items[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(items[i].ratio<items[j].ratio){
                struct Obj temp=items[i];
                items[i]=items[j];
                items[j]=temp;
            }
        }
    }
}
int main(){
    int n;
    float capacity;
    printf("Enter number of items:");
    scanf("%d",&n);
    struct Obj items[n];
    printf("Enter profit and weight for each item:\n");
    for(int i=0; i<n; i++){
        scanf("%d %d",&items[i].profit,&items[i].weight);
        items[i].ratio=(float)items[i].profit/items[i].weight;
        items[i].index=i+1;
    }
    printf("Enter knapsack capacity:");
    scanf("%f",&capacity);
    sort(items,n);
    float totalProfit=0.0;
    printf("\nSelected items:\n");
    for(int i=0; i<n; i++){
        if(items[i].weight<=capacity){
            capacity-=items[i].weight;
            totalProfit+=items[i].profit;
            printf("Item %d  -> FULL\n",items[i].index);
        }else{
            float x=capacity/items[i].weight;
            totalProfit+=items[i].ratio*capacity;
            printf("Item %d -> FRACTION %.2f\n",
                   items[i].index, x);
            break;
        }
    }
    printf("\nMaximum profit=%.2f\n",totalProfit);
    return 0;
}
