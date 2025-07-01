#include <functional>

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* previous = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        std::function<void(TreeNode*)> inorderTraversal = [&](TreeNode* node) {
            if (!node) return;
            inorderTraversal(node->left);
            if (previous && previous->val > node->val) {
                if (!first) first = previous;
                second = node;
            }
            previous = node;
            inorderTraversal(node->right);
        };

        inorderTraversal(root);
        if (first && second) std::swap(first->val, second->val);
    }
};