class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0; i<nums.size(); ++i) {
            int ans = nums[i];
            cnt += (ans == k);
            for(int j=i+1; j<nums.size(); ++j) {
                ans = __gcd(ans, nums[j]);
                cnt += (ans == k);
                if(ans < k) break;
            }

        }
        return cnt;
    }
};