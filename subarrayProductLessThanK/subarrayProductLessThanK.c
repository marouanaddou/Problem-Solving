

# include <stdio.h>
# include <stdlib.h>

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) 
{
    if ( k <= 1 ) return 0;
    int cont = 0;
    int windowPro = 1;
    int start = 0;
    int end = 0;
    for ( ; end < numsSize && start < numsSize; )
    {
        if (windowPro * nums[end] < k)
        {
            windowPro *= nums[end++];
            cont += end - start;
        }
        else if ( windowPro * nums[end] >= k && end != start) 
            windowPro /= nums[start++];
        else 
        {
            start++;
            end++;
        }
    }
    return cont;
}

// int main()
// {
//     int arr[] = {1,1,1};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     numSubarrayProductLessThanK(arr, size, 1);
// }
