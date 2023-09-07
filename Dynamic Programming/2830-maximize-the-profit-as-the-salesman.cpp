class Solution {
public:
    int dp[100001];
    int solve(int ind, vector<vector<int>> &offers) {
    if(ind >= offers.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
    int ans = solve(ind+1, offers);
    int lo = ind+1, hi = offers.size()-1, mid;
    
    while(lo <= hi) {
        mid = lo+(hi-lo)/2;
        if(offers[mid][0] > offers[ind][1]) hi = mid-1;
        else lo = mid+1;
    } 

    ans = max(ans, offers[ind][2] + solve(lo, offers));
    return dp[ind] = ans;

}

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        memset(dp,-1,sizeof(dp));
        sort(begin(offers), end(offers));
        return solve(0, offers);
    }
};