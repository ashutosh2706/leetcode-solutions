class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        long long ans = 0;
        map<int,int> mp;
        for(int i=0; i<nums.size(); ++i) mp[nums[i]]++;
        if(--mp[nums.front()] == 0) mp.erase(nums.front());
        long long maxi = nums[0];
        for(int i=1; i<nums.size()-1; ++i) {
            if(--mp[nums[i]] == 0) mp.erase(nums[i]);
            int it = prev(mp.end())->first;
            ans = max(ans, (long long)(maxi - 1LL*nums[i]) * (long long)it);
            maxi = max(maxi, (long long)nums[i]);
        }
        return ans;
    }
};