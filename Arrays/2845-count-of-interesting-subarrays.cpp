class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        long long ans = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        int pref = 0;
        for(int i=0; i<nums.size(); i++) {
            pref += (nums[i] % m == k);
            int r = pref % m;
            int target = (r-k+m)%m;
            ans += map[target];
            map[r]++;
        }
        return ans;
    }
};