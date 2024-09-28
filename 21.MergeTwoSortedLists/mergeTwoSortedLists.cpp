

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        ListNode *head;
        if (list1->val >= list2->val) {
            head = new ListNode(list2->val);
            list2 = list2->next;
        }
        else {
            head = new ListNode(list1->val);
            list1 = list1->next;
        }
        ListNode *tmp = head;
        for (;list1 != nullptr && list2 != nullptr;) {
            if (list1->val >= list2->val){
                tmp->next = new ListNode(list2->val);
                list2 = list2->next;
                tmp = tmp->next;
            }
            else {
                tmp->next = new ListNode(list1->val);
                list1 = list1->next;
                tmp = tmp->next;
            }
        }
        for (;list1 != nullptr; list1 = list1->next) {
            tmp->next = new ListNode(list1->val);
            tmp = tmp->next;
        }
        for (;list2 != nullptr; list2 = list2->next) {
            tmp->next = new ListNode(list2->val);
            tmp = tmp->next;
        }
        return head;
    }
};