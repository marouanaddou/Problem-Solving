

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
    TreeNode* invertTree(TreeNode* root) {

        if (root == nullptr) return root;

        std::queue<TreeNode*> q;
        q.push(root);

        while ( !q.empty() ) {
            int size = q.size();

            while ( size-- ) {

                TreeNode* tmp = q.front();
                q.pop();

                if ( tmp->left != nullptr&& tmp->right != nullptr)  {
                    TreeNode* tmp1 = tmp->left;
                    TreeNode* tmp2 = tmp->right;

                    tmp->left = tmp2;
                    tmp->right = tmp1;

                    q.push(tmp->left);
                    q.push(tmp->right);
                }
                else if ( tmp->left == nullptr&& tmp->right != nullptr ) {
                    TreeNode* tmp2 = tmp->right;

                    tmp->left = tmp2;
                    tmp->right = nullptr;

                    q.push(tmp->left);
                }
                else if ( tmp->left != nullptr&& tmp->right == nullptr ) {
                    TreeNode* tmp1 = tmp->left;

                    tmp->left = nullptr;
                    tmp->right = tmp1;
                    
                    q.push(tmp->right);
                }
            } 
        }
        return root;
    }
};