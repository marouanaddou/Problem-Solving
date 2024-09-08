
# include <iostream>
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
    ListNode* endOfList(ListNode* head) {
        ListNode* tmp = head;
        for (;tmp->next != nullptr && tmp->next->next != nullptr; ) tmp = tmp->next;
        ListNode* last = tmp->next;
        tmp->next = nullptr;
        return last;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tmp = head;
        int size = 0;
        for (;tmp != nullptr; size++) tmp = tmp->next;
        if (size <= 1 || k == 0) return head;
        if (size < k)
            k = k % size;
        for (int i = 0; i < k; i++) {
            tmp = endOfList(head);
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};