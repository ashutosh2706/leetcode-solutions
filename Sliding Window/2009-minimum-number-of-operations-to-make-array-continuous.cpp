class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int N = nums.size();
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));

        int l = 0, ans = 0;
        for(int r=0; r<nums.size(); r++) {
            while(nums[l] + N <= nums[r]) l++;
            ans = max(ans, r-l+1);
        }
        return N- ans;
    }
};