class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int cnt = 0;
        unordered_set<int> st;
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] <= k) st.insert(nums[i]);
            cnt++;
            if((int)st.size() == k) break;
        }
        return cnt;
    }
};