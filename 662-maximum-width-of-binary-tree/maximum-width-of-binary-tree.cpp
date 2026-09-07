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
        queue<pair<int,TreeNode*>> q;
        int maxWidth = 0;
        q.push({0,root});
        while(!q.empty()){
            int n = q.size();
            int width = 1;
            int left,right;
            for(int i = 0; i< n ; i++){
                TreeNode* curr = q.front().second;
                long long  index = q.front().first;
                q.pop();
                if(curr->left) q.push({index*2 + 1, curr->left});
                if(curr->right) q.push({index*2 + 2, curr->right});
                if(i == n-1) right = index;
                if(i == 0) left = index;
            }
            maxWidth = max(maxWidth , right - left + 1);


        }
        return maxWidth;
    }
};