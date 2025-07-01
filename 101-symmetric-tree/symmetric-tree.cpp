#include <functional>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*, TreeNode*)> checkSymmetry = [&](TreeNode* left, TreeNode* right) {
            if (!left && !right) return true;
            if (!left || !right || left->val != right->val) return false;
            return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
        };
        return checkSymmetry(root, root);
    }
};