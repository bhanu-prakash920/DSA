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
    void good(TreeNode* root , int m , int &count){
        if(!root) return;
        if(root->val >= m) {
            m = root->val;
           count++;
        }
        good(root->left,m,count);
        good(root->right,m, count);
        
    }
    int goodNodes(TreeNode* root) {
        int m = INT_MIN;
        int count = 0;
        good(root , m,count);
        return count;

        
    }
};