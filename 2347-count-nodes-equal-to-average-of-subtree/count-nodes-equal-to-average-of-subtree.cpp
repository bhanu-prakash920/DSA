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
    int count(TreeNode* root){
        if(!root) return 0;
        int leftsum = count(root->left);
        int rightsum = count(root->right);

        return leftsum+rightsum+1;
    }
    int sum(TreeNode* root, int &ans){
        if(!root) return 0;
        int leftsum = sum(root->left , ans);
        int rightsum = sum(root->right, ans);
        if((leftsum+rightsum+root->val )/ count(root) == root->val){
            ans++;
        }

        return leftsum+rightsum+root->val;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        sum(root,ans);
        
        return ans;
        
    }
};