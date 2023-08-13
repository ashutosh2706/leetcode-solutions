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
    ListNode* doubleIt(ListNode* head) {
        string s = "", res = "";
        ListNode* tmp = head;
        while(tmp) {
            s += tmp->val + '0';
            tmp = tmp->next;
        }
        reverse(begin(s), end(s));
        int carry = 0;
        for(auto &c : s) {
            int x = (c - '0')*2 + carry;
            res += ((x%10) + '0');
            carry = x/10;
        }
        if(carry) res += carry + '0';
        reverse(begin(res), end(res));
        ListNode *start = new ListNode(res[0] - '0');
        ListNode * t = start;
        for(int i=1; i<res.length(); ++i) {
            t->next = new ListNode(res[i] -'0');
            t = t->next;
        }
        return start;
    }
};