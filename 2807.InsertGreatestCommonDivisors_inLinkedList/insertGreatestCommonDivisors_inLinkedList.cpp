
# include <iostream>
#include <numeric>
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* next = head->next;
        for (;next != nullptr;) {
            ListNode* tmp = new ListNode(curr->val * next->val / lcm(curr->val , next->val));
            curr->next = tmp;
            curr = curr->next;
            curr->next = next;
            curr = next;
            next = next->next;
        }
        return head;
    }
};