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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> g(501);

        auto construct_dfs = [&](auto&& self, TreeNode* v, TreeNode* p) -> void {
            if (v->left) {
                g[v->val].push_back(v->left->val);
                self(self, v->left, v);
            }

            if (v->right) {
                g[v->val].push_back(v->right->val);
                self(self, v->right, v);
            }

            if (p) {
                g[v->val].push_back(p->val);
            }
        };

        construct_dfs(construct_dfs, root, nullptr);

        vector<int> current = { target->val };
        vector<int> next;
        vector<bool> vis(501, false);
        vis[target->val] = true;

        for (int dist = 0; dist < k; ++dist) {
            for (auto v : current) {
                for (auto u : g[v]) {
                    if (vis[u]) continue;

                    vis[u] = true;
                    next.push_back(u);
                }
            }

            current = std::move(next);
            next.clear();
        }

        return current;
    }
};
