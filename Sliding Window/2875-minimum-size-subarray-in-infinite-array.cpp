class Solution {
#define int long long int
public:
    int32_t minSizeSubarray(vector<int32_t>& nums, int32_t target) {
    int n = nums.size(), sum = 0, len=0;
    for(auto &i : nums) sum += i;

    if(target%sum == 0) {
        return n*(target/sum);
    }

    vector<int> pf(begin(nums), end(nums));
    for(auto &a:nums) pf.emplace_back(a);
    len = n*(target/sum);
    target -= (target/sum) * sum;

    unordered_map<int,int> mp;
    mp[0]=-1;
    mp[pf[0]]=0;
    for(int i=1; i<(2*n); ++i) {
         pf[i] += pf[i-1];
         mp[pf[i]]=i;
    }

    int ans = INT_MAX;
    for(int i=0; i<pf.size(); ++i) {
        if(pf[i] >= target and mp.count(pf[i] - target)) {
            ans = min(ans, i-mp[pf[i]-target]);
        }
    }
    return ans == INT_MAX ? -1 : ans+len;
    #undef int
    }
};