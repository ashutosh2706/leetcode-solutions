/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* start = head;
        Node* tmp = NULL;
        Node* t;
        unordered_map<Node*, Node*> map;
        while(start) {
            if(tmp == NULL) {
                tmp = new Node(start->val);
                t = tmp;
                map[start] = tmp;
                map[tmp] = start;
                start = start->next;
                continue;
            }

            t->next = new Node(start->val);
            t = t->next;
            map[t]=start;
            map[start] = t;
            start = start->next;

        }
        start = head;
        t = tmp;

        while(start) {
            if(start->random == NULL) {
                t->random = NULL;
                t = t->next;
                start = start->next;
                continue;
            }

            t->random = map[start->random];
            t = t->next;
            start = start->next;
        }
        return tmp;
    }
};