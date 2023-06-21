class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int N = nums.size(), mid, l = 0, r = N-1, ans = 0;
        if(N%2) mid = nums[N/2];
        else mid = (nums[N/2] + nums[(N/2) - 1])/2;

        while(l <= r) {
            ans += abs(nums[l++] - mid);
            ans += abs(nums[r--] - mid);
        }
        return ans;
    }
};