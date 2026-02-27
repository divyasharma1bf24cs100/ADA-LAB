/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int freq[201]={0};
    for(int i=0;i<numsSize;i++){
        freq[nums[i]+100]++;
    }
    for(int i=0;i<numsSize-1;i++){
        for(int j=0;j<numsSize-i-1;j++){
            int f1=freq[nums[j]+100];
            int f2=freq[nums[j+1]+100];
            if(f1>f2 || (f1==f2 && nums[j]<nums[j+1])){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    return nums;
}
