// DP with binary search

class Solution {
public:
long long func(int curr, int prev, vector<int>& nums1, vector<int>& nums2, map<pair<int,int>, int>& dp) {

    if(curr == nums1.size()) return 0;
    if(dp.count({curr, prev})) return dp[make_pair(curr, prev)];
    long long skip = INT_MAX, replace = INT_MAX;
    if(nums1[curr] > prev) skip = func(curr+1, nums1[curr], nums1, nums2, dp);
    auto ind = upper_bound(begin(nums2),end(nums2),prev) - begin(nums2);
    if(ind < nums2.size()) replace = 1 + func(curr+1, nums2[ind], nums1, nums2, dp);
    return dp[{curr,prev}] = min(skip, replace);

}
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2), end(arr2));
        map<pair<int,int>, int> dp;
        long long ans = func(0, INT_MIN, arr1,arr2,dp);
        return ans >= INT_MAX ? -1 : ans;
    }
};