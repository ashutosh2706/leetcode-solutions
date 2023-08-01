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
    unordered_map<string, int> map;
    vector<TreeNode*> res;
    string duplicate(TreeNode* root) {
        if(root == NULL) return "null";
        string ss = to_string(root->val) + " " + duplicate(root->left) + " " + duplicate(root->right);
        map[ss]++;
        if(map[ss] == 2) res.push_back(root);
        return ss;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        duplicate(root);
        return res;
    }
};