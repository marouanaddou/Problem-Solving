
# include <iostream>
# include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

        // int size = nums.size();
        // int max = *max_element(nums.begin(), nums.end());
        // long long result = 0;
        // int cont = 0;
        // for (int i = 0; i < size; i++)
        // {
        //     cont = 0;
        //     for(int j = i; j < size; j++)
        //     {
                
        //         if (nums[j] == max)
        //             cont++;
        //         if (cont >= k)
        //             ans++;
        //     }
        // }
        // return ans;

static long long countSubarrays(vector<int>& nums, int k) {
    // int size = nums.size();
    // long long result = 0;
    
    // Find the maximum element in the array
    // int maxElement = *max_element(nums.begin(), nums.end());
    
    // int left = 0, right = 0, maxCount = 0;

    // // Iterate through the array with a sliding window
    // while (right < size) {
    //     // If the current element is the maximum element, increase the count
    //     if (nums[right] == maxElement)
    //         maxCount++;
        
    //     // Shrink the window if the condition is not satisfied
    //     while (maxCount >= k && left <= right) {
    //         result += size - right;
    //         if (nums[left] == maxElement)
    //             maxCount--;
    //         left++;
    //     }
        
    //     right++;
    // }
    int size = nums.size();
        int max = *max_element(nums.begin(), nums.end());
        long long result = 0;
        int cont = 0;
        for (int l = 0, r = 0; r < size;r++)
        {
            if (max == nums[r])
                cont++;
            while(cont == k && l <= r)
            {
                result += size - r;
                if (nums[l] == max)
                    cont--;
                l++;
            }
        }
    return result;
}
};

// int main()
// {
//     vector<int> vec{61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82};
//     Solution cont;
//     printf("%lld", cont.countSubarrays(vec, 2));
// }

// #include <vector>
// #include <unordered_map>
// #include <iostream>

// using namespace std;

// int countSubarrays(const vector<int>& nums, int k) {
//     int n = nums.size();
//     int result = 0;

//     unordered_map<int, int> frequency;

//     for (int left = 0, right = 0; right < n; ++right) {
//         // Update frequency of the current element
//         frequency[nums[right]]++;

//         // Shrink the window from the left until the condition is satisfied
//         while (frequency.empty() || frequency.begin()->first < k) {
//             frequency[nums[left]]--;
//             if (frequency[nums[left]] == 0) {
//                 frequency.erase(nums[left]);
//             }
//             left++;
//         }

//         // Add the count of subarrays ending at the current position
//         result += right - left + 1;
//     }

//     return result;
// }
// #include <algorithm>
// class Solution {
//  public:
//   static long long countSubarrays(vector<int>& nums, int k) {
//     int maxNum = *std::max_element(nums.begin(), nums.end());
//     long long ans = 0;
//     int count = 0;

//     for (int l = 0, r = 0; r < nums.size(); ++r) {
//       if (nums[r] == maxNum)
//         ++count;
//       // Keep the window to include k - 1 times of the maximum number.
//       while (count == k)
//         if (nums[l++] == maxNum)
//           --count;
//       // If l > 0, nums[l..r] has k - 1 times of the maximum number. For any
//       // subarray nums[i..r], where i < l, it will have at least k times of the
//       // maximum number, since nums[l - 1] equals the maximum number.
//       ans += l;
//     }

//     return ans;
//   }
// };
int main() {
    // Example usage
    vector<int> nums1 = {1, 3, 2, 3, 3};

    vector<int> vec{61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82};
    int k1 = 2;
    cout << "Output for nums1: " << Solution::countSubarrays(vec, k1) << endl;

    vector<int> nums2 = {1, 4, 2, 1};
    int k2 = 3;
    cout << "Output for nums2: " << Solution::countSubarrays(nums2, k2) << endl;

    return 0;
}
