/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    bool reach[100][100] = {false};
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        reach[u][v] = true;
    }
    for (int k = 0; k < numCourses; k++) {
        for (int i = 0; i < numCourses; i++) {
            for (int j = 0; j < numCourses; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    bool* ans = (bool*)malloc(sizeof(bool) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        ans[i] = reach[u][v];
    }
    *returnSize = queriesSize;
    return ans;
}
