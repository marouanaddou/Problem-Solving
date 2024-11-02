

# include <iosream>
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        priority_queue < long long > maxHeap;

        std::queue<TreeNode*> q;
        q.push(root);
        long long sum, count;

        while( !q.empty() ) {

            count = q.size();
            sum = 0;
            while ( count > 0 ) {

                TreeNode* tmp = q.front();
                q.pop();
                sum += tmp->val;
                if ( tmp->left != nullptr ) q.push(tmp->left);
                if ( tmp->right != nullptr ) q.push(tmp->right); 
                count--;

            }

            maxHeap.push(sum);
        }
        if (maxHeap.size() < k) return -1;
        for ( ; k > 1; k-- ) {
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};