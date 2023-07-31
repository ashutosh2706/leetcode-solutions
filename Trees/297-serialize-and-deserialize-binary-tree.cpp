/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    vector<string> serialize(TreeNode* root) {
        if(root == nullptr) return {};
        vector<string> v;
        v.push_back(to_string(root->val));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode *t = q.front();
                q.pop();
                if(t->left) {
                    q.push(t->left);
                    v.push_back(to_string(t->left->val));
                } else v.push_back("null");
                if(t->right) {
                    q.push(t->right);
                    v.push_back(to_string(t->right->val));
                } else v.push_back("null");
            }
        }


        return v;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(vector<string> nodes) {
        if(nodes.size() == 0) return nullptr;
        int p = 0;
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(nodes[p++]));
        q.push(root);
        while(!q.empty() && p < nodes.size()) {
            int sz = q.size();
            while(sz--) {
                TreeNode *t = q.front(), *new_node;
                q.pop();
                if(nodes[p] != "null") {
                    q.push(new_node = new TreeNode(stoi(nodes[p])));
                    t->left = new_node;
                }p++;
                if(nodes[p] != "null") {
                    q.push(new_node = new TreeNode(stoi(nodes[p])));
                    t->right = new_node;
                }p++;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));