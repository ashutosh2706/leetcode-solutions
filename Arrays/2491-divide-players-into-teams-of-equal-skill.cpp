class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
    int N = nums.size();
    long long sum = accumulate(begin(nums), end(nums), 0);
    if(sum%(N/2)) return -1;
    long long ans = 0;
    long long rem = sum/(N/2);
    sort(begin(nums),end(nums));
    int l=0, r=N-1;
    while(l < r) {
        if(nums[l] + nums[r] != rem) return -1;
        ans += (nums[l] * nums[r]);
        l++; r--;
    }
    return ans;
    }
};