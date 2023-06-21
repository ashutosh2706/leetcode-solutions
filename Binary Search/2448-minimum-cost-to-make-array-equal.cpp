class Solution {
public:
    typedef long long int ll;
    ll getcost(int v, vector<int>& nums, vector<int>& cost) {
        ll costs = 0;
        for(int i=0; i<nums.size(); i++) {
            costs += ((ll)abs(nums[i] - v) * (ll)cost[i]);
        }
        return costs;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {

        
        int lo = *min_element(begin(nums),end(nums));
        int hi = *max_element(begin(nums), end(nums));
        int mid;

        ll ans = LLONG_MAX;
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            ll c1 = getcost(mid, nums, cost);
            ll c2 = getcost(mid+1, nums, cost);
            ans = min({ans, c1, c2});
            if(c1 < c2)  hi = mid-1;
            else lo = mid+1;
        }
        return ans;
    }
};