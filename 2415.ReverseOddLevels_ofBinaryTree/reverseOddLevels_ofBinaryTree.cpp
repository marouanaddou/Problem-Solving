

# include <iostream>
# include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        if ( root == nullptr ) return root;
        
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;

        q1.push(root);
        q2.push(root);

        int level = 0;

        while ( !q1.empty() ) {

            int size = q1.size();
            std::deque<int> d;

            while ( size-- ) {

                TreeNode* tmp = q1.front();
                q1.pop();

                if ( level % 2 == 1 ) d.push_back(tmp->val);

                if ( tmp->left != nullptr ) q1.push(tmp->left);
                if ( tmp->right != nullptr ) q1.push(tmp->right);

            }

            size = q2.size();

            while ( size-- ) {

                TreeNode* tmp = q2.front();
                q2.pop();

                if ( level % 2 == 1 ) {
                    int a = d.back();
                    d.pop_back();
                    tmp->val = a;
                }

                if ( tmp->left != nullptr ) q2.push(tmp->left);
                if ( tmp->right != nullptr ) q2.push(tmp->right);
            }
            level += 1;
        }
        return root;
    }
};