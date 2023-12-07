/*
Similar problem:
https://leetcode.com/problems/minimum-number-of-coins-to-be-added/
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        sort(begin(nums), end(nums));
        long long sum = 0, cnt = 0;
        for(int i=0; i<nums.size();) {
            if(sum >= n) return cnt;
            if(nums[i] > (sum+1)) {
                ++cnt;
                sum = 2*sum + 1;
            } else 
                while(i < nums.size() and nums[i] <= (sum+1)) sum += nums[i++];
        }

        while(sum < n) {
            ++cnt;
            sum = 2*sum + 1;
        }

        return cnt;
    }
};
