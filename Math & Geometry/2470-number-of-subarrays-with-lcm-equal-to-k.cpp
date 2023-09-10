class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        
        int cnt = 0;
        for(int i=0; i<nums.size(); ++i) {
            int ans = 1;
            for(int j=i; j<nums.size(); ++j) {
                ans = (ans * nums[j])/__gcd(ans, nums[j]);
                cnt += ans == k;
                if(ans > k) break;
            }
        }
        return cnt;
    }
};