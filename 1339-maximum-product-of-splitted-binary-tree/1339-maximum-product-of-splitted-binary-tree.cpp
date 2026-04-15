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
    static constexpr int MOD = 1'000'000'007;
    long long best = 0;      // 最大乘積（未取 mod）
    long long total = 0;     // 全樹總和

    long long subtree_sum(TreeNode* node) {
        if (!node) return 0;
        return (long long)node->val + subtree_sum(node->left) + subtree_sum(node->right);
    }

    long long dfs(TreeNode* node) {
        if (!node) return 0;

        long long s = (long long)node->val + dfs(node->left) + dfs(node->right);

        // 切在「這個子樹」和「其餘部分」之間
        long long product = s * (total - s);
        if (product > best) best = product;

        return s;
    }

    int maxProduct(TreeNode* root) {
        total = subtree_sum(root);  // 先算全樹總和
        dfs(root);                  // 再用各子樹 sum 更新最大乘積
        return (int)(best % MOD);
    }
};