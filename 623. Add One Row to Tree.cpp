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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* root1 = new TreeNode(val);
            root1->left = root;
            root1->right = NULL;
            return root1;
        }
        queue<TreeNode*> q;
        TreeNode* root1 = root;
        q.push(root);
        int x = 1;
        while (!q.empty()) {
            int size = q.size();
            x++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (x == depth) {
                    TreeNode* temp = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = temp;
                    node->left->right = NULL;
                    temp = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = temp;
                    node->right->left = NULL;
                }
                else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            if (x == depth) break;
        }
        return root1;
    }
};
