/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> sum(TreeNode* root, int& ans) {
        if(!root) return {0,0};
        auto [leftSum, leftCount] = sum(root->left, ans);
        auto [rightSum, rightCount] = sum(root->right, ans);

        int sum = leftSum + rightSum + root->val;
        int count = leftCount + rightCount + 1;

        if (sum / count == root->val) {
            ans++;
        }

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        sum(root, ans);

        return ans;
    }
};