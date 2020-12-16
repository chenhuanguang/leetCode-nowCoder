/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int k, int* returnSize){

    int len =0;
    int temp = k;
    while(temp)
    {
        len++;
        temp/=10;
    }
    int arrlen = ASize>len ? ASize+1:len+1;
    int *arr = (int*)malloc(sizeof(int)*(arrlen+1));
  
    int end = ASize-1;
    int step = 0;
    int sum = 0;
    int idx = 0;
    while(end>=0 || k>0)
    {
        sum = step;
        if(end>=0)
            sum += A[end];
        if(k>0)
            sum += k%10;
        if(sum>9)
        {
            step=1;
            sum-=10;
        }
        else
        {
            step =0;
        }
        arr[idx++] = sum;
        end--;
        k/=10;
    }

    if(step == 1)
        arr[idx++]=1;

    int start = 0;
    int end1 = idx-1;
    while(end1>start)
    {
        arr[start] = arr[start]^arr[end1];
        arr[end1] = arr[start]^arr[end1];
        arr[start] = arr[start]^arr[end1];
        end1--;
        start++;
    }
    *returnSize = idx;
    return arr;
}