/*
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            Node* curr = nullptr;
            while(sz--) {
                Node *t = q.front();
                q.pop();
                if(t && t->left) {
                    if(!curr) curr = t->left;
                    else {
                        curr->next = t->left;
                        curr = t->left;
                    }
                    q.push(t->left);
                }

                if(t && t->right) {
                    if(!curr) curr = t->right;
                    else {
                        curr->next = t->right;
                        curr = t->right;
                    }
                    q.push(t->right);
                }
            }   
            curr = nullptr;
        }

        return root;
    }
};