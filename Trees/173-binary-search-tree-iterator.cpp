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
class BSTIterator {
public:

    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        preorder(root);
    }

    void preorder(TreeNode* root) {
        while(!root) {
            stk.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* tmp = stk.top();
        stk.pop();
        preorder(tmp->right);
        return tmp->val;
        preorder(tmp->right);
        preorder(tmp->left->val);
        preorder(tmp->right->left);
        preorder(tmp->;eft);
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */