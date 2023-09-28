class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
    unordered_map<int,long long> mp;
    long long ans = 0, pairs = 0, n = nums.size();
    int l=0, r=0;
    for(; r<n; ++r) {
        while(l<r and pairs>=k) {
            // dbg(r)
            ans += (n-(r-1));
            mp[nums[l]]--;
            pairs -= mp[nums[l++]];
        }
        pairs += mp[nums[r]]++;
    }
    while(l<r and pairs>=k) {
        ans += (n-(r-1));
        mp[nums[l]]--;
        pairs -= mp[nums[l++]];
    }
    return ans;
    }
};

