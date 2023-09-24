class Solution {
public:
    typedef long long int ll;
    ll sum(vector<int> &nums, int ind) {
            
        ll ans = 0;
        int l = ind-1, r = ind+1, prev = nums[ind];
        while(l>=0) {
            if(nums[l] >= prev) ans += prev;
            else {
                ans += nums[l];
                prev = nums[l];
            }
            l--;
        }
        prev = nums[ind];
        while(r < nums.size()) {
            if(nums[r] >= prev) ans += prev;
            else {
                ans += nums[r];
                prev = nums[r];
            }
            r++;
        }
        return ans + nums[ind];
        
    }
    long long maximumSumOfHeights(vector<int>& nums) {
        
        ll ans = 0;
        int n = nums.size();
        for(int i=0; i<n; ++i) {
            ans = max(ans, sum(nums, i));
            
        }
        return ans;
    }
};