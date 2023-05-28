class Solution {
private:
int f(int i, int j, vector<int> &cuts, map<pair<int,int>,int> &dp) {

    if(dp.count({i,j})) return dp[{i,j}];
    int ans = 0;
    int start = lower_bound(begin(cuts),end(cuts),i+1) - begin(cuts);
    for(int k=start; k<cuts.size() and cuts[k]<j; k++) {
        if(ans == 0) ans = 1e9;
        ans = min(ans, (j-i) + f(i,cuts[k],cuts,dp) + f(cuts[k],j,cuts,dp));
    }
    return dp[{i,j}] = ans;
}
public:
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));
        map<pair<int,int>, int> dp;
        return f(0,n,cuts,dp);
    }
};
