class Solution {
public:
    int heightandbalance(TreeNode* cur) {
        if (cur == nullptr) {
            return 0;
        }

        int left = heightandbalance(cur->left);
        if (left == -1) return -1;

        int right = heightandbalance(cur->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return heightandbalance(root) != -1;
    }
};