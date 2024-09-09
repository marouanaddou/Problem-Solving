


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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, std::vector<int>(n, -1));
        ListNode* tmp =  head;
        int i = 0,j = 0, dir= 0; 
        for (;tmp != nullptr; ) {
            if (matrix[i][j] == -1) {
                if (dir == 0) {
                    for (;j < n && matrix[i][j] == -1 && tmp != nullptr;j++) {
                        matrix[i][j] = tmp->val;
                        tmp = tmp->next;
                    }
                    i++;
                    j--;
                    dir = 1;
                }
                else if (dir == 1) {
                    for (;i < m && matrix[i][j] == -1 && tmp != nullptr;i++) {
                        matrix[i][j] = tmp->val;
                        tmp = tmp->next;
                    }
                    i--;
                    j--;
                    dir = 2;
                }
                else if (dir == 2) {
                    for (;j > -1 && matrix[i][j] == -1 && tmp != nullptr;j--) {
                        matrix[i][j] = tmp->val;
                        tmp = tmp->next;
                    }
                    j++;
                    i--;
                    dir = 3;
                }
                else {
                    for (;i > -1 && matrix[i][j] == -1 && tmp != nullptr;i--) {
                        matrix[i][j] = tmp->val;
                        tmp = tmp->next;
                    }
                    i++;
                    j++;
                    dir = 0;
                }
            }
        }
        return matrix;
    }
};