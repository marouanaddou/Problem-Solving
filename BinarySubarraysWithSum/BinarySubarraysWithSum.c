
# include <stdio.h>

int numSubarraysWithSum(int* nums, int numsSize, int goal)
{
    int begin = 0;
    int end = 0;
    int total = 0;
    int nuSubArr = 0;
    for (int i = 0;/*i < numsSize || begin < i*/ ;)
    {
        total += nums[i];
        printf ("%d\n", i);
        if (total == goal)
        {
            end = i;
            nuSubArr += 1;
            printf("%d %d\n", begin, end);
        }
        else
        {
            if (total > goal)
            {
                total -= nums[begin];
                begin += 1;
            }
            end = i;
            printf("%d %d %d\n", begin, end, total);
            if (total == goal)
            {
                nuSubArr += 1;
            }
        }
            printf("%d %d %d\n", begin, end, total);

        if (i == numsSize)
            begin++;
        if ((i == numsSize && total < goal) || begin == numsSize)
        {
            printf("%d %d\n", begin, numsSize);
            break;
        }
        else if (i < numsSize)
            i++;
    }
    return nuSubArr;
}

int main()
{
    int nums[5] = {1,0,1,0,1};
    printf ("%d", numSubarraysWithSum(nums, 5, 2) );
}