class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> map;
        long long ans = 0 , sum = 0;
        for(int i=0; i<k; i++) {
            sum += nums[i];
            map[nums[i]]++;
        }
        if(map.size() >= m) ans = max(ans, sum);
        for(int l=0, r=k; r<nums.size(); ++r) {
            while((r-l+1) > k) {
                if(--map[nums[l]] == 0) map.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            map[nums[r]]++;
            sum += nums[r];
            if(map.size() >= m) ans = max(ans, sum);
        }
        return ans;
    }
};