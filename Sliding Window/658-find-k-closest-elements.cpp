class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
    if(k == nums.size()) return nums;

    int l = 0, r = 0, maxdiff = -1, n = nums.size();

    while(r < k) {
        if(maxdiff == -1) maxdiff = abs(nums[r] - x);
        else maxdiff = max(maxdiff, abs(nums[r] - x));
        r++;
    }
    while(r < n) {

        if(abs(nums[r] - x) >= maxdiff && (nums[l] != nums[r])) break;
        r++;

        maxdiff = abs(nums[++l] - x);
    }
    vector<int> ret;
    for(auto it = l; it < r; it++) ret.push_back(nums[it]);
    return ret;
    }
};