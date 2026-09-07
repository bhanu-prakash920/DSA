/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void collect(TreeNode* root, int k, vector<int>& ans) {
        if (!root || k < 0)
            return;
        if (k == 0)
            ans.push_back(root->val);
        collect(root->left, k - 1, ans);
        collect(root->right, k - 1, ans);
    }
    int dfs(TreeNode* root, TreeNode* target, int k, vector<int>& ans) {
        if (!root)
            return -1;
        if (root == target) {
            collect(target, k, ans);
            return 0;
        }
        int left = dfs(root->left, target, k, ans);
        if (left != -1) {
            int dist = 1 + left;
            if (dist == k) {
                ans.push_back(root->val);

            } else {
                collect(root->right, k - dist - 1, ans);
            }
            return dist;
        }
        int right = dfs(root->right, target, k, ans);
        if (right != -1) {
            int dist = 1 + right;
            if (dist == k) {
                ans.push_back(root->val);

            } else {
                collect(root->left, k - dist - 1, ans);
            }
            return dist;
        }
        return -1;

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        dfs(root, target,k,ans);
        return ans;
    }
};