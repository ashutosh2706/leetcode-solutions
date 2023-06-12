class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = 1e9, ans, sum;
        sort(begin(nums),end(nums));
        for(int i=0; i<nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if(sum > target) r--;
                else l++;
                if(abs(target-sum) < diff) {
                    ans = sum;
                    diff = abs(target-sum);
                }
            }
        }
        return ans;
    }
};