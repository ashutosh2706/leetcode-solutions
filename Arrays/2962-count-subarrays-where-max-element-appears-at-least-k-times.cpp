class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int ele = *max_element(begin(nums), end(nums)), l=0, r=0;
        long long res = 0, cnt = 0;
        for(; r<nums.size(); ++r) {
            if(nums[r] == ele) ++cnt;
            while(cnt >= k) {
                if(nums[l] == ele) --cnt;
                l++;
            }
            res += (r-l+1);
        }
        long long n = nums.size(), tot;
        tot = (n*(n+1))/2;
        return tot-res;
    }
};