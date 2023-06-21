class Solution {
public:
    typedef long long int ll;
    
    long long cost(int v, vector<int>& nums) {
        long long costs = 0;
        for(auto &a:nums) costs += 1L * abs(a-v);
        return costs;
    }
    int minMoves2(vector<int>& nums) {
        
        int lo = *min_element(begin(nums), end(nums));
        int hi = *max_element(begin(nums), end(nums)), mid;

        ll ans = INT_MAX;
        while(lo <= hi) {
            mid = lo+(hi-lo)/2;
            ll c1 = cost(mid, nums);
            ll c2 = cost(mid+1, nums);
            ans = min({ans,c1,c2});
            if(c1 < c2) hi = mid-1;
            else lo = mid+1;
        }
        return ans;
    }
};