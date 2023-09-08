class Solution {
public:
long long dp[100001];
typedef long long int ll;
ll solve(int ind, vector<vector<int>> &rides) {
    if(ind >= rides.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
    ll ans = solve(ind+1, rides);
    int lo = ind+1, hi = rides.size()-1, mid;
    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        if(rides[mid][0] >= rides[ind][1]) {
            hi = mid-1;
        }else lo = mid+1;
    }
    return dp[ind] = max(ans, ((ll)rides[ind][1]-(ll)rides[ind][0]+(ll)rides[ind][2]) + solve(lo, rides));
}

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        memset(dp,-1,sizeof(dp));
        sort(begin(rides),end(rides));
        return solve(0, rides);

    }
};