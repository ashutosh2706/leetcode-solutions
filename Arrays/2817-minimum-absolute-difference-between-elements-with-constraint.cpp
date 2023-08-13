class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> set;
        int ans = INT_MAX;
        for(int l=0, r=x; r < nums.size(); ++r) {
            set.insert(nums[l++]);
            auto pre = set.lower_bound(nums[r]);
            if(pre != begin(set)) {
                int i = *(prev(pre));
                ans = min(ans, abs(nums[r] - i));
            }
            if(pre != set.end()) {
                ans = min(ans, abs(nums[r] - *pre));
            }
            pre = set.upper_bound(nums[r]);
            if(pre != end(set)) {
                ans = min(ans, abs(nums[r] - *pre));
            }
        }
        return ans;
    }
};