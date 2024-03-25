


int* findDuplicates(int* nums, int numsSize, int* returnSize) 
{
    int *arr = (int *)calloc(numsSize + 1, sizeof(int));
    int *result = (int *)malloc(numsSize * 4);
    int cont = 0;
    for (int i = 0; i < numsSize; i++)
    {
        arr[nums[i]]++;
        if (arr[nums[i]] > 1)
            result[cont++] = nums[i];
    }
    *returnSize = cont;
    free(arr);
    return result;
}