class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

    int n = nums.size();
    int rem = 0;
    for(auto &i:nums)
        rem = (rem + i)%p;
    if(rem == 0)  return 0;
    map<int, int> map;
    map[0] = -1;
    int ans = n;
    long long sum = 0;
    for(int i=0; i<n; i++) {
        sum += nums[i];
        int val = sum%p - rem;
        if(val < 0) val += p;
        if(map.count(val)) ans = min(ans, i - map[val]);
        map[sum%p] = i; 
    }
    return ans == n ? -1 : ans;
    }
};