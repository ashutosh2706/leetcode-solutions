class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
    int ans = 0, prev = 0, cnt = 1;
    for(int r=1,l=0; r<nums.size(); r++) {
        int d = nums[r] - nums[r-1];
        if(prev == 0) {
            if(d == 1) {
                prev = d;
                l = r-1;
                ans = max(ans,r-l+1);
            }
            continue;
        }

        if(abs(d) != 1) {
            prev = 0;
            l = r;
            continue;
        }

        if(prev == d) {
            l = r-1;
        }else {
            prev *= -1;
            ans = max(ans, r-l+1);
        }
    }
        if(ans == 0) return -1;
        return ans;
    }
};