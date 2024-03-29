

# include <stdio.h>
# include <stdlib.h>

int maxSubarrayLength(int* nums, int numsSize, int k) 
{
    int maxSize = 0;
    int maxLenght = 0;
    int *mp;
    for (int i = 0; i < numsSize; i++)
        if(maxSize < nums[i])
            maxSize = nums[i];
    mp = (int *)calloc(maxSize , sizeof(int));
    for (int start = 0, end = 0; start < numsSize && end < numsSize;)
    {
        while (mp[nums[end]] + 1> k)
            mp[nums[start++]]--;
        if (maxLenght < end - start + 1)
            maxLenght = end - start + 1;
        mp[nums[end++]]++;
    }
    free(mp);
    return maxLenght;
}

// int main()
// {
//     int nums[] = {1,4,4,2};
//     printf("%d",maxSubarrayLength(nums,4,1));
// }