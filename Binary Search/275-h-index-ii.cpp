class Solution {
public:
    int hIndex(vector<int>& nums) {
        
    auto cited = [](vector<int> &nums, int &val) {
        auto a = end(nums) - lower_bound(begin(nums), end(nums), val);
        return a >= val;
    };
    int lo = 0, hi = nums.size(), mid;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        if(cited(nums, mid)) lo = mid+1;
        else hi = mid-1;
    }
    return hi;

    }
};