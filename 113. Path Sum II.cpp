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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int targetSum, int sum, vector<int> &vec) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (sum + root->val == targetSum) {
                vec.push_back(root->val);
                ans.push_back(vec);
                vec.pop_back();
            }
            return;
        }
        vec.push_back(root->val);
        dfs(root->left, targetSum, sum + root->val, vec);
        dfs(root->right, targetSum, sum + root->val, vec);
        vec.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return {};
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == root->val) {
                vector<int> vec;
                vec.push_back(targetSum);
                return {vec};
            }
            return {};
        }
        vector<int> vec;
        dfs(root, targetSum, 0, vec);
        // vector<vector<int>> ans;
        // for (auto &it: collect) {
        //     if (it.size() > 1) ans.push_back(it);
        // }
        return ans;
    }
};
