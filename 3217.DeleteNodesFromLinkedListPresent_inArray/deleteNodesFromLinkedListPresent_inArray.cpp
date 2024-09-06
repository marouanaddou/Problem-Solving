



# include <iostram>
# include <vector>
#include <set> 

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::set<int> setNums(nums.begin(), nums.end());
        for (;head != nullptr;) {
            if (setNums.find(head->val) != setNums.end()) {
                head = head->next;
            }
            else {
                break;
            }
        }
        ListNode* tmp = head;
        int j = 0;
        for (;tmp != nullptr && tmp->next != nullptr;) {
            if (setNums.find(tmp->next->val) != setNums.end()) {
                tmp->next = tmp->next->next;
            }
            else {
                tmp = tmp->next;
            }
        }
        return head;
    }
};