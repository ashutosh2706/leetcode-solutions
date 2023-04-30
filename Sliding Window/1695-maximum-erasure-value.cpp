class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, ans = 0, sum = 0;
        unordered_set<int> S;
        for(int r = 0; r < nums.size(); r++) {
            while(S.find(nums[r]) != S.end()) {
                S.erase(nums[l]);
                sum -= nums[l++];
            }
            S.insert(nums[r]);
            sum += nums[r];
            ans = max(ans, sum);
        }
        return ans;
    }
};