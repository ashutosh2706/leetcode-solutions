class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int p1 = nums.size()-2, p2 = nums.size()-1;
        int ans = INT_MAX;
        while(p1 >= 0) {
            ans = min(ans, abs(nums[p1]-nums[p2]));
            p1--; p2--;
        }
        return ans;
    }
};