class Solution {
public:
    #define ll long long int
    long long maximumOr(vector<int>& nums, int k) {
        vector<ll> p(nums.size()), s(nums.size());
        k = pow(2,k);
        if(nums.size() == 1) return (ll)k*(ll)nums[0];
        p[0] = nums[0];
        s.back() = nums.back();
        for(int i=1; i<nums.size(); ++i) p[i] = p[i-1] | nums[i];
        for(int i=nums.size()-2; i>=0; --i) s[i] = s[i+1] | nums[i];
        ll ans = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(i == 0) ans = max(ans, ((ll)k*(ll)nums[i]) | s[i+1]);
            else if(i == nums.size()-1) ans = max(ans, ((ll)k*(ll)nums[i]) | p[i-1]);
            else ans = max(ans, ((ll)k*(ll)nums[i]) | p[i-1] | s[i+1]);
        }
        return ans;
    }
};