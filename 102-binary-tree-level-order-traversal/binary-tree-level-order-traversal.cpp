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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            vector<int> current_level_nodes;

            for (int i = 0; i < level_size; ++i) {
                TreeNode* current_node = q.front();
                q.pop();
                current_level_nodes.push_back(current_node->val);

                if (current_node->left != nullptr) {
                    q.push(current_node->left);
                }
                if (current_node->right != nullptr) {
                    q.push(current_node->right);
                }
            }
            result.push_back(current_level_nodes);
        }
        return result;
    }
};