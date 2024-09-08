
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        std::vector<ListNode*> ans;
        if (head == nullptr) {
            for (; k >0; k--) ans.push_back(nullptr);
            return ans;
        }
        int size = 0;
        ListNode* tmp = head;
        ListNode* tmpNext = head->next;
        for (; tmp != nullptr; size++) tmp =tmp->next;
        if (k > size) {
            for (tmp = head;tmp != nullptr;) {
                tmpNext = tmp->next;
                tmp->next = nullptr;
                ans.push_back(tmp);
                tmp = tmpNext;
            }
            k = k - size;
            for(;k >0; k--) ans.push_back(nullptr);
        }
        else {
            int div = size / k;
            int mod = size % k;
            mod / 2;
            bool x = 0;
            ListNode* push;
            tmp = head;
            for (int i = 0; i < k; i++) {
                x = 0;
                int j = 0;
                for ( ;tmp != nullptr && j < div; j++) {
                    if (x == 0) {
                        push = tmp;
                        x = 1;
                    }
                    else {
                        tmp = tmp->next;
                    }
                }
                if (mod > 0) {
                    mod--;
                    tmp = tmp->next;
                }
                if (tmp->next != nullptr)
                    tmpNext = tmp->next;
                tmp->next = nullptr;
                tmp = tmpNext;
                ans.push_back(push);
            }
        }
        return ans;
    }
};