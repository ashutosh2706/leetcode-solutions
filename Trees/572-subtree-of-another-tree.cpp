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
private:
bool same(TreeNode* r, TreeNode* s) {

    if(!r && !s) return 1;
    if(!r || !s) return 0;
    if(r->val != s->val) return 0;
    return same(r->left, s->left) && same(r->right, s->right); 

}


public:
    bool isSubtree(TreeNode* r, TreeNode* s) {
        if(!s) return 0;
        if(same(r,s)) return 1;
        if(r) return isSubtree(r->left, s) || isSubtree(r->right, s);
        return 0;
    }
};