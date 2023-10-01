class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int a = -1, cnt=0;
        for(auto &i:nums) a = a&i;
        if(a != 0) return 1;
        a = -1;
        for(int i=0; i<nums.size(); ++i) {
            a = a&nums[i];
            if(a == 0) {
                a = -1;
                cnt ++;
            }
        }
        return a==0 ? cnt+1 : cnt;
        
    }
};