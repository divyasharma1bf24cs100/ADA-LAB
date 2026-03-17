#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int mid1,int high){
    int i,j,k;
    int *b=(int *)malloc((high+1)*sizeof(int));
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
            b[k]=a[i];
            k++;i++;
        }
        else{
            b[k]=a[j];
            k++;j++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;k++;
    }
    while(j<=high){
        b[k]=a[j];
        k++;j++;
    }
    for(i=low;i<=high;i++){
        a[i]=b[i];
    }
    free(b);
}
void mergesort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,mid+1,high);
    }
}
void main(){
    int n;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    int low=0;
    int high=n-1;
    clock_t start=clock();
    mergesort(a,low,high);
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds",time_taken);
    free(a);
}

