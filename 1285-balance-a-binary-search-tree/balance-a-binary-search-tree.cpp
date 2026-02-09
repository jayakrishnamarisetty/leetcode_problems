/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& a) {
        if (root) {
            inorder(root->left, a);
            a.push_back(root->val);
            inorder(root->right, a);
        }
    }
    
    TreeNode* rug(const vector<int>& a, int n, int m) {
        if (n > m) return nullptr;
        int mi = (n + m) / 2;
        TreeNode* root = new TreeNode(a[mi]);
        root->left = rug(a, n, mi - 1);
        root->right = rug(a, mi + 1, m);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a;
        inorder(root, a);
        return rug(a, 0, a.size() - 1);
    }
};
