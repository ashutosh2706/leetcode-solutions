/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int len = 0;
        ListNode* tmp = head;
        while(tmp) {
            len++;
            tmp=tmp->next;
        }
        vector<ListNode*> res;
        if(len < k) {
            tmp=head;
            while(k--) {
                if(tmp) {
                    res.emplace_back(new ListNode(tmp->val));
                    tmp = tmp->next;
                }
                else res.emplace_back(nullptr);
            }
        }else {
            int d = len/k, r = len%k;
            tmp = head;
            while(k--) {
                ListNode* start = nullptr;
                int t = d + (r-- > 0);

                while(t--) {
                    ListNode* new_node = new ListNode(tmp->val);
                    tmp = tmp->next;
                    if(start == nullptr) {
                        start = new_node;
                        res.emplace_back(start);
                    } else {
                        start->next = new_node;
                        start = start->next;
                    }
                }
            }
        }

        return res;
    }
};