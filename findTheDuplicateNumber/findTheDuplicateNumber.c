
# include <stdio.h>
# include <stdlib.h>

int findDuplicate(int* nums, int numsSize) 
{
    int *arr = (int *)calloc(numsSize , sizeof(int));  // Allocate memory for a new array and initialize it with values set to 0.
    for ( int i = 0; i < numsSize; i++ )
    {
        arr[nums[i]]++;
        if ( arr[nums[i]] >= 2 ) return nums[i];
    }
    return 0;
}

/********************** TEST ***********************/

int main()
{
    int arr[] = {1,2,3,4,2};
    printf ("%d\n", findDuplicate(arr, 5));
}

/********************** TEST ***********************/
