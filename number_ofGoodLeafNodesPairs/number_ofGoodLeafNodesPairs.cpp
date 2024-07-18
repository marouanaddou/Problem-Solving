
# include <iostream>
# include <vector>
# include <string>

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
    std::vector<int> leaf;
    int count;

    TreeNode* traverce(TreeNode* root){
        if (root == nullptr) return nullptr;
        root->val = count++;
        root->left = traverce(root->left);
        root->right = traverce(root->right);
        if (root->left == nullptr && root->right == nullptr)
        {
            root->val = count++;
            leaf.push_back(root->val);
        }
        return root;
    }

    bool lca(TreeNode* root, int val, std::string &path){
        if (root == nullptr) return 0;
        if (root->val == val) return true;
        path += 'L';
        if (lca(root->left, val, path))
            return true;
        path.pop_back();
        path += 'R';
        if (lca(root->right, val, path))
            return true;
        path.pop_back();
        return false;
    }

    int countPairs(TreeNode* root, int distance) {
        root = traverce(root);
        int size = leaf.size();
        int count = 0;
        std::vector<std::pair<std::string, int>> paths(size);
        std::string path;
        for (int i = 0; i < size; i++)
        {
            lca(root, leaf[i], path);
            paths[i] = std::make_pair(path, path.size());
            path.clear();
        }
        int idx = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i+ 1; j < size; j++)
            {
                for (idx = 0; idx < paths[i].second && idx < paths[j].second 
                    && paths[i].first[idx] ==paths[j].first[idx]; idx++);
                if ((paths[i].second - idx) + (paths[j].second - idx) <= distance) 
                    count++;  
            }
        }
        return count;
    }
};