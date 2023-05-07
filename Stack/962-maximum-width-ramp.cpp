class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> S;
        int n = nums.size(), ans = 0;
        for(int i=0; i<n; i++) {
            if(S.empty() or nums[S.top()] > nums[i]) 
                S.push(i);
        }
        for(int i=n-1; i>=0; i--) {
            while(!S.empty() and nums[S.top()] <= nums[i]) {
                ans = max(ans, i - S.top());
                S.pop();
            }
        }
        return ans;
    }
};