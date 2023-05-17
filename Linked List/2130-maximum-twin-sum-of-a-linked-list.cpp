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
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode* tmp = head;
        while(tmp) {
            vec.push_back(tmp->val);
            tmp=tmp->next;
        }

        int l = 0, r = vec.size()-1, ans = 0;
        while(l < r) {
            ans = max(ans, vec[l++] + vec[r--]);
        }
        return ans;
    }
};