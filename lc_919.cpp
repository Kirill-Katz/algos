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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        vector<TreeNode*> layer;
        layer.push_back(root);

        while (!layer.empty()) {
            vector<TreeNode*> cur;

            for (TreeNode* tn : layer) {
                if (tn->left != nullptr) {
                    cur.push_back(tn->left);
                }

                if (tn->right != nullptr) {
                    cur.push_back(tn->right);
                }
            }

            layers.push_back(layer);
            layer = std::move(cur);
        }

        if (layers.size() == 1) {
            layers.push_back({});
        }
    }

    int insert(int val) {
        TreeNode* tn = new TreeNode{val};

        if (layers[layers.size() - 2].back()->right != nullptr) {
            layers.push_back({});
        }

        int current = (int)layers[layers.size() - 1].size();
        int prev_idx = current / 2;

        TreeNode* parent = layers[layers.size() - 2][prev_idx];

        if(layers[layers.size() - 2][prev_idx]->left == nullptr) {
            layers[layers.size() - 2][prev_idx]->left = tn;
        } else {
            layers[layers.size() - 2][prev_idx]->right = tn;
        }

        layers[layers.size() - 1].push_back(tn);
        return parent->val;
    }

    TreeNode* get_root() {
        return layers[0][0];
    }
private:
    vector<vector<TreeNode*>> layers;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
