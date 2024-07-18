

# include <stdio.h>
# include <stdlib.h>

long long countSubarrays(int* nums, int numsSize, int k) 
{
    int max = 0;
    long long cont = 0;
    int start = 0;
    int end = 0;
    for (; start < numsSize; start++)
        if(nums[start] > max)
            max = nums[start];
    int *mp = (int *)calloc(max + 1, 4);
    for (start = 0; start < numsSize && end < numsSize;)
    {
        if (++mp[nums[end]] >= k)
        {
            while(mp[nums[end]] >= k)
            {
                cont++;
                --mp[nums[start++]];
            }
        }
        end++;
        // if (end < numsSize)
        // {
        //     if (++mp[nums[end++]] >= k)
        //     {
        //     printf("%d %d\n", start, end);
        //         cont++;
        //     }
        // }
        // else
        // {
        //     printf("%d %d\n", start, end);
        //     --mp[nums[start++]];
        //     for (int j = start; j < numsSize; j++)
        //     {
        //         if (mp[nums[j++]] >= k)
        //         {
        //             cont++;
        //             break;
        //         }
        //     }
        //     // if (--mp[nums[start++]] >= k)
        //     //     cont++;
        // }
        printf("xx");
    }
    return cont;
}

int main()
{
    int arr[] = {1,3,2,3,3};
    printf("%lld",countSubarrays(arr, 5, 2));
}
