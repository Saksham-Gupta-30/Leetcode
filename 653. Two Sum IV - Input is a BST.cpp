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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val)
            return root;
        if (root->val > val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);
    }
    void preorder(TreeNode* root, vector<int>& traverse) {
        if (root != NULL) {
            traverse.push_back(root->val);
            preorder(root->left, traverse);
            preorder(root->right, traverse);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> traverse;
        preorder(root, traverse);
        for (auto it: traverse) {
            TreeNode* temp = searchBST(root, k - it);
            if (temp != NULL && temp->val != it) return true;
        }
        return false;
    }
};
