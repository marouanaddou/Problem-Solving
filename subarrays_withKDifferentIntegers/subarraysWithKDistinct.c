

# include <stdio.h>
# include <stdlib.h>

// // int subarraysWithKDistinct(int* nums, int numsSize, int k) 
// // {
// //     int *mp = (int *)calloc(numsSize + 1, sizeof(int));
// //     int cont = 1;
// //     int result = 0;
// //     mp[nums[0]]++;
// //     for ( int left = 0, right = 0; right < numsSize - 1/*|| left < numsSize*/; )
// //     {
// //         // if (mp[nums[right]] == 0) 
// //         // {
// //         //     mp[nums[right]]++;
// //         //     cont++;
// //         // }
// //         // if (cont == k && mp[nums[right + 1]] != 0)
// //         // {
// //         //     printf ("left -> %d right -> %d\n", left, right);
// //         //     result++;
// //         // }
// //         // if (/*mp[nums[right + 1]] == 0 &&*/ cont > k)
// //         // {
// //         //     while (++left < right /*&& cont == k*/)
// //         //     {
// //         //         printf ("left -> %d right -> %d\n", left, right);
// //         //         if (--mp[nums[left]] == 0) cont--;
// //         //         // left++;
// //         //         result++;
// //         //     }
// //         // }
// //         if (mp[nums[right + 1]] == 0)
// //         {
// //             if (cont < k)
// //             {
// //                 mp[nums[right + 1]]++;
// //                 cont++;
// //             }
// //             else 
// //             {
// //                 while (left < right && cont == k)
// //                 {
// //                     result++;
// //                     --mp[nums[left++]];
// //                 }
// //                 cont--;
// //             }
// //         }
// //         else if (cont == k && mp[nums[right + 1]] != 0)
// //             result++;
// //         // if (cont == k && mp[nums[right + 1]] != 0)
// //         // {
// //         //     result++;
// //         // }

// //         printf ("%d %d %d %d\n", cont, right, nums[right], mp[nums[right]]);
// //         right++;
// //     }
// //     return result;
// // }
int subarraysWithKDistinct(int* nums, int numsSize, int k) 
{
    int *mp = (int *)calloc(numsSize + 1, sizeof(int));
    int cont = 0;
    int result = 0;
    // mp[nums[0]]++;
    for ( int left = 0, right = 0; right < numsSize /*|| left < numsSize*/; )
    {
        if (mp[nums[right]] == 0)
        {
            cont++;
            ++mp[nums[right]];
            printf("ri -> %d %d %d\n", right, mp[nums[right]], nums[right]);
        }
        else
            ++mp[nums[right]];
        if (cont == k)
        {
            int temp = left;
            while(cont == k && temp < right)
            {
                if (mp[nums[temp]] == 1) break;
                result++;
                temp++;
            }
            // result++;
        }
        if (cont > k)
        {
            // right--;
            // cont--;
            // printf("cont ->%d \n", cont);
            while(left < right && cont == k)
            {
                printf("%d\n", mp[nums[left]]);
                if (--mp[nums[left]] == 0)
                {
                    if (cont-- < k) break;
                }
                result++;
                left++;
            }
            // printf("left %d\n", left);
            // printf("%d %d %d \n", cont, result, right);
            // break;
        }
        right++;
    }
    printf("%d", cont);
    // printf("%d %d\n", result, right);
    return result;
}

int main()
{
    int nums[] = {1,2};
    printf ("%d", subarraysWithKDistinct(nums,5, 1));
}


// #include <stdio.h>
// #include <stdlib.h>

// int subarraysWithKDistinct(int* nums, int numsSize, int k) {
//     int result = 0;
//     int left1 = 0, left2 = 0;
//     int distinct1 = 0, distinct2 = 0;
//     int *count1 = (int *)calloc(numsSize + 1, sizeof(int));
//     int *count2 = (int *)calloc(numsSize + 1, sizeof(int));

//     for (int right = 0; right < numsSize; right++) {
//         if (count1[nums[right]] == 0) distinct1++;
//         count1[nums[right]]++;
//         if (count2[nums[right]] == 0) distinct2++;
//         count2[nums[right]]++;

//         while (distinct1 > k) {
//             count1[nums[left1]]--;
//             if (count1[nums[left1]] == 0) distinct1--;
//             left1++;
//         }

//         while (distinct2 >= k) {
//             count2[nums[left2]]--;
//             if (count2[nums[left2]] == 0) distinct2--;
//             left2++;
//         }

//         result += left2 - left1;
//     }

//     free(count1);
//     free(count2);
//     return result;
// }

// int main() {
//     int nums[] = {1, 2};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int k = 1;
//     int result = subarraysWithKDistinct(nums, numsSize, k);
//     printf("Subarrays with %d different integers: %d\n", k, result);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int subarraysWithKDistinct(int* nums, int numsSize, int k) {
//     int result = 0;
//     int left = 0;
//     int distinctCount = 0;
//     int *count = (int *)calloc(numsSize + 1, sizeof(int));

//     for (int right = 0; right < numsSize; right++) {
//         if (count[nums[right]] == 0) distinctCount++;
//         count[nums[right]]++;

//         while (distinctCount > k) {
//             count[nums[left]]--;
//             if (count[nums[left]] == 0) distinctCount--;
//             left++;
//         }

//         // If distinct count is exactly k, increment result
//         if (distinctCount == k) {
//             result++;

//             // Further increment result as long as next element is the same
//             int tempLeft = left;
//             while (distinctCount == k && tempLeft < right) {
//                 if (count[nums[tempLeft]] == 1) break;
//                 tempLeft++;
//                 result++;
//             }
//         }
//     }

//     free(count);
//     return result;
// }

// int main() {
//     int nums[] = {1, 2, 1, 2, 4};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int k = 2;
//     int result = subarraysWithKDistinct(nums, numsSize, k);
//     printf("Subarrays with %d different integers: %d\n", k, result);
//     return 0;
// }
