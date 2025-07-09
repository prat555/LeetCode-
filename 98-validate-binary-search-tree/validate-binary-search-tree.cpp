class Solution {
private:
    TreeNode* prev;

    bool inorder(TreeNode* node) {
        if (!node) return true;
        if (!inorder(node->left)) return false;
        if (prev && prev->val >= node->val) return false;
        prev = node;
        if (!inorder(node->right)) return false;
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        prev = nullptr;
        return inorder(root);
    }
};