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

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<long long,TreeNode*>> q;
        int maxWidth = 0;
        q.push({0,root});
        while(!q.empty()){
            int n = q.size();
            int width = 1;
            int mmin = 0;
            for(int i = 0; i< n ; i++){
                TreeNode* curr = q.front().second;
                if(i == 0) mmin = q.front().first;
                long long index = q.front().first - mmin;
                q.pop();
                if(curr->left) q.push({2*index + 1, curr->left});
                if(curr->right) q.push({2*index + 2, curr->right});
                if(i == n-1) width += index;
                if(i == 0) width -= index;
            }
            maxWidth = max(maxWidth , width);


        }
        return maxWidth;
    }
};