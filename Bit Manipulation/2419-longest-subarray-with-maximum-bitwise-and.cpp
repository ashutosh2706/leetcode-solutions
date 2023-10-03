class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cm = -1, gm = -1;
        int s = 0,len=0,ans=0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] > (cm&nums[i])) {
                cm = nums[i];
                s = i;
                len = 1;
            } else {
                cm = cm & nums[i];
                len = max(len, i-s+1);
            }
            if(cm == gm) ans = max(ans, len);
            else if(cm > gm) {
                ans = len;
                gm = cm;
            }
        }
        
        return ans;
    }
};