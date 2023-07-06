class Solution {
private:
bool possible(int ws, vector<int>& nums, int& t) {
    int sum = 0;
    for(int l=0, r=0; r<nums.size(); r++) {
        sum += nums[r];
        if(r-l+1 > ws) {
            sum -= nums[l];
            l++;
        }
        if(sum >= t) return 1;
    }
    return 0;
}
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(begin(nums), end(nums), 0) < target) return 0;
        int lo = 1, hi = nums.size(), mid;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(possible(mid,nums,target)) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};