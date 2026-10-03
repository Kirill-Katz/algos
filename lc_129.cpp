class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;

        auto dfs = [&] (auto&& self, TreeNode* node, int current) {
            if (node->left == node->right && node->left == nullptr) {
                ans += current * 10 + node->val;
                return;
            }

            if (node->left) {
                self(self, node->left, current * 10 + node->val);
            }

            if (node->right) {
                self(self, node->right, current * 10 + node->val);
            }
        };

        dfs(dfs, root, 0);
        return ans;
    }
};
