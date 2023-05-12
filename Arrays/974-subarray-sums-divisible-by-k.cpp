class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ans = 0, rem;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            if(i==0){
                rem = nums[0]%k;
                rem = rem < 0 ? rem + k : rem;
                ans += map[rem];
                map[rem]++;
                continue;
            }
            nums[i] += nums[i-1];
            rem = nums[i] % k;
            rem = rem < 0 ? rem + k : rem;
            ans += map[rem];
            map[rem]++;
        }
        return ans;
    }
};