

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
    void insertAtFront(ListNode** head, int val)
    {
        ListNode* new_node = new ListNode();
        new_node->val = val;
        new_node->next = (*head);
        (*head) = new_node;
    }

    ListNode* doubleIt(ListNode* head) 
    {
        ListNode *tmp  = head;
        vector<int> vec;
        int rest = 0;
        int res = 0;
        int i;
        for (; tmp != NULL;)
        {
            vec.push_back(tmp->val);
            tmp = tmp->next;
        }
        for (i = vec.size() - 1; i >= 0; i--)
        {
            res = vec[i] * 2;
            vec[i] = ((vec[i] * 2) % 10) + rest; 
            rest = res / 10;
        }
        i = 0;
        if (res >= 10)
        {
            vec.insert(vec.begin(), res / 10); 
            insertAtFront(&head, vec[i++]);
            tmp = head->next;
        }
        else 
            tmp = head;
        for(;tmp != NULL; i++)
        {
            tmp->val = vec[i];
            tmp = tmp->next;
        }
        return head;
    }
};