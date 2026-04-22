int findTargetSumWays(int* nums, int numsSize, int target){
    int total=0;
    for(int i=0; i<numsSize; i++){
        total+=nums[i];
    }
    if((target+total)%2!=0||abs(target)>total){
        return 0;
    }
    int P=(target+total)/2;
    int* dp=(int*)calloc(P+1,sizeof(int));
    dp[0]=1;
    for(int i=0; i<numsSize; i++){
        for(int j=P; j>=nums[i]; j--){
            dp[j]+=dp[j-nums[i]];
        }
    }
    int result=dp[P];
    free(dp);
    return result;
}
