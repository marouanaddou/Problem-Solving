

# include <stdio.h>
# include <stdlib.h>

long long countSubarrays(int* nums, int numsSize, int k) 
{
    int max = 0;
    long long result = 0;
    int cont = 0;
    int l = 0, r = 0;
    for (; l < numsSize; l++)
        if(nums[l] > max)
            max = nums[l];
    for (l = 0; r < numsSize;r++)
    {
        if (max == nums[r]) cont++;
        while(cont == k && l <= r)
        {
            result += numsSize - r;
            if (nums[l] == max)
                cont--;
            l++;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1,3,2,3,3};
    printf("%lld",countSubarrays(arr, 5, 2));
}
