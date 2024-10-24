

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        if (root1 == nullptr && root2 == nullptr) return true;
        if ( (root1 == nullptr && root2 != nullptr)  || (root1 != nullptr && root2 == nullptr) ) return false;
        if (root1->val != root2->val) return false;
        
        std::queue<TreeNode*> q1, q2;
        q1.push(root1), q2.push(root2);

        while ( !q1.empty() ) {

            int size = q1.size();
            while ( size-- ) {

                TreeNode* tmp1 = q1.front();
                q1.pop();

                TreeNode* tmp2 = q2.front();
                q2.pop();

                if (    ( tmp1->left == nullptr && tmp2->left != nullptr ) 
                        || (tmp1->right == nullptr && tmp2->right != nullptr) 
                        || ( tmp1->left != nullptr && tmp2->left == nullptr ) 
                        || (tmp1->right != nullptr && tmp2->right == nullptr) 
                        || (tmp1->left != nullptr && tmp2->left != nullptr  && tmp1->left->val != tmp2->left->val))  {
                    TreeNode* tmp11 = tmp1->left;
                    TreeNode* tmp12 = tmp1->right;
                    tmp1->left = tmp12;
                    tmp1->right = tmp11;

                    if ( tmp1->left != nullptr && tmp2->left != nullptr && tmp1->left->val != tmp2->left->val) return false;
                    if ( ( tmp1->left == nullptr && tmp2->left != nullptr ) 
                        || (tmp1->right == nullptr && tmp2->right != nullptr) 
                        || ( tmp1->left != nullptr && tmp2->left == nullptr ) 
                        || (tmp1->right != nullptr && tmp2->right == nullptr) ) return false;
                }
                if (tmp1->left != nullptr) q1.push(tmp1->left);
                if (tmp1->right != nullptr) q1.push(tmp1->right);
                if (tmp2->left != nullptr) q2.push(tmp2->left);
                if (tmp2->right != nullptr) q2.push(tmp2->right);
            }
        }
        return true;
    }
};