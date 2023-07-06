class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    int rem = accumulate(begin(nums), end(nums), 0) - x;
    long long len = -1, sum = 0;   // maximize
    for(int l=0, r=0; r < nums.size(); r++) {
        sum += nums[r];
        while(l < nums.size() and sum > rem) {
            sum -= nums[l];
            l++;
        }
        if(sum == rem) len = max(len, 1LL * (r-l+1));
    }
    if(len == -1) return len;
    return nums.size() - len; 
    }
};