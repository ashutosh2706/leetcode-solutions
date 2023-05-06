class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        Node* tmp;
        int sz;
        while(!q.empty()) {
            sz = q.size();
            for(int i=1; i<=sz; i++) {
                Node* temp = q.front();
                q.pop();
                if(i==1) tmp=temp;
                else {
                    tmp->next = temp;
                    tmp = tmp->next;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            tmp->next=NULL;
        }
        return root;
    }
};