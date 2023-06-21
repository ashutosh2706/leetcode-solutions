class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(begin(nums),end(nums));
        long long diff = nums.back() - nums.front();
        long long ans = diff;
        for(int i=1; i<nums.size() - 1; i++) {
            int x = nums[i] + diff;
            ans += abs(nums.back() - x);
        }
        return ans;
    }
};   