class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int cnt = nums.front() > 0, n = nums.size();
        for(int i=0; i<n-1; ++i) {
            if((i+1) > nums[i] and (i+1) < nums[i+1]) 
                cnt++;
        }

        cnt += n > nums.back();
        return cnt;
    }
};