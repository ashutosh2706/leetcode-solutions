class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 1;
        vector<int> lis(nums.size(), 1);
        for(int i=0; i<nums.size(); ++i) {
            for(int j=i+1; j<nums.size(); ++j) {
                if(nums[j] >= nums[i]) {
                    lis[j] = max(lis[j], 1 + lis[i]);
                    cnt = max(cnt, lis[j]);
                }
            }
        }
        return (int)nums.size() - cnt;
    }
};