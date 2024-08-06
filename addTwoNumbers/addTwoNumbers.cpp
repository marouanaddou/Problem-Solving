


# include <iostream>
# include <string>

using namespace std
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void bfs(ListNode* root, std::string &nb)
    {
        if (root == nullptr) return;
        nb.push_back(root->val + '0');
        bfs(root->next, nb);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        std::string nb1;
        std::string nb2;
        bfs(l1, nb1);
        bfs(l2, nb2);
        std::string result;
        int rest = 0;
        int sum = 0;
        int i = 0;
        for (; i < nb1.size() && i < nb2.size(); i++)
        {
            sum = (nb1[i] - '0') + (nb2[i] - '0') + rest;
            if (sum >= 10)
            {
                result.push_back((sum % 10) + '0');
                rest = sum / 10;
            }
            else 
            {
                result.push_back((sum % 10)+ '0');
                rest = 0;
            }
        }
        while(i < nb1.size())
        {
            sum = (nb1[i] - '0') + rest;
            if (sum >= 10)
            {
                result.push_back((sum % 10)+ '0');
                rest = sum / 10;
            }
            else 
            {
                result.push_back((sum % 10)+ '0');
                rest = 0;
            }
            i++;
        }
        while(i < nb2.size())
        {
            sum = (nb2[i] - '0') + rest;
            if (sum >= 10)
            {
                result.push_back((sum % 10)+ '0');
                rest = sum / 10;
            }
            else 
            {
                result.push_back((sum % 10)+ '0');
                rest = 0;
            }
            i++;
        }
        if (rest > 0)
            result.push_back(rest + '0');
        ListNode* tmp = l1;
        for (int i = 0; i < result.size() && tmp != nullptr;i++)
        {
            tmp->val = result[i] - '0';
            if (tmp->next == nullptr && i + 1 != result.size())
                tmp->next = new ListNode();
            tmp = tmp->next;
        }
        return l1;
    }
};