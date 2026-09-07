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
    int good(TreeNode* root , int m){
        if(!root) return 0;
        if(root->val >= m) {
            m = max(m ,root->val );
            return 1+ good(root->left,m) + good(root->right,m);
        }
        return good(root->left,m) + good(root->right,m);
        
    }
    int goodNodes(TreeNode* root) {
        int m = INT_MIN;
        int count = good(root , m);
        return count;

        
    }
};