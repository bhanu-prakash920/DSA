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
    void getParentNodes(TreeNode* root,
                        unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;
        if (root->left)
            parent[root->left] = root;
        if (root->right)
            parent[root->right] = root;
        getParentNodes(root->left, parent);
        getParentNodes(root->right, parent);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target)
            return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;
        vector<int> res;
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        vis[target] = true;
        getParentNodes(root, parent);
        q.push(target);
        while (k > 0 && !q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }

                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }

                if (parent[curr] && !vis[parent[curr]]) {
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
            k--;
        }
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
}

;