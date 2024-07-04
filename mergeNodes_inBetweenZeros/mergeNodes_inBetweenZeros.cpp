
# include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode *fast = head->next;
        ListNode *slow = head;
        int sum = 0;
        for(;fast != nullptr;)
        {
            if (fast->val != 0)
            {
                sum += fast->val;
                fast = fast->next;
                continue;
            }
            slow->val = sum;
            if (fast->next != nullptr)
                slow = slow->next;
            else
                slow->next = nullptr;
            sum = 0;
            fast = fast->next;
        }
        return head;
    }
};