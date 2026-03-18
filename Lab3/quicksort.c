#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int low,int high){
    int i,j,pivot;
    i=low;
    j=high;
    pivot=a[low];
    while(i<j){
        while(pivot>=a[i] && i<=high-1){
            i++;
        }while(pivot<a[j] && j>=low+1){
            j--;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[low],&a[j]);
    return j;
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int k=partition(a,low,high);
        quicksort(a,low,k-1);
        quicksort(a,k+1,high);
    }
}
int main(){
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    clock_t start=clock();
    quicksort(a,0,n-1);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds",time_taken);
    free(a);
    return 0;
}
