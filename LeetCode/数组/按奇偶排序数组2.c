int* sortArrayByParityII(int* A, int ASize, int* returnSize){
int* ans = malloc(sizeof(int) * ASize);
    int add = 0;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            ans[add] = A[i];
            add += 2;
        }
    }
    add = 1;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 1) {
            ans[add] = A[i];
            add += 2;
        }
    }
    *returnSize = ASize;
    return ans;
}