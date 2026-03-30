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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        //cache
        queue<TreeNode*> queue;
        queue.push(root);

        int depth = 0;
        while(!queue.empty()) {
            int queue_size = queue.size(); //重要！
            for (int i = 0; i<queue_size ; i++) {
                //operate
                TreeNode* node = queue.front();
                queue.pop();
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
