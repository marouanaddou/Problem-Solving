
# include <iostream>
# include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverceList(ListNode* head)
    {
        if (head != NULL)
        {
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = head->next;
            for (;curr != NULL;)
            {
                curr->next = prev;
                prev = curr;
                curr = next;
                if (next != NULL)
                    next = next->next;
            }
            head = prev;
        }
        return head;
    }

    ListNode* removeNodes(ListNode* head) 
    {
        vector<int> result;
        head = reverceList(head);
        int max = head->val;
        ListNode* tmp = head;
        for(;tmp != NULL;)
        {
            if(max > tmp->val)
            {
                if (find(result.begin(), result.end(), max) == result.end())
                    result.push_back(max);
            }
            else 
            {
                max = tmp->val;
                result.push_back(max);
            }
            tmp = tmp->next;
        }
        tmp = head;
        if (result.size() > 0)
        {
            int i = result.size() - 1;
            for (; i  > 0; i--)
            {
                tmp->val = result[i];
                tmp = tmp->next;
            }
            tmp->val = result[0];
            tmp->next = NULL;
        }
        return (head);
    }
};

