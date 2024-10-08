




You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

 

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]

Output: [4,5]

Explanation:

![linkedlistexample0](https://github.com/user-attachments/assets/1bd4e3fd-491b-4d94-8008-7819f95944c1)

Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]

Output: [2,2,2]

Explanation:

![linkedlistexample1](https://github.com/user-attachments/assets/a1384ed4-7383-45f3-beaf-4f524b1e1b62)

Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]

Output: [1,2,3,4]

Explanation:

No node has value 5.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 105
    All elements in nums are unique.
    The number of nodes in the given list is in the range [1, 105].
    1 <= Node.val <= 105
    The input is generated such that there is at least one node in the linked list that has a value not present in nums.

