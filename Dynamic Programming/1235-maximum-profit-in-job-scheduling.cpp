class Solution {
public:
int dp[50001];
int solve(int ind, vector<vector<int>> &jobs) {
    if(ind >= jobs.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
    int ans = solve(ind+1, jobs);
    int lo = ind+1, hi = jobs.size()-1, mid;
    while(lo <= hi) {
        mid = lo+(hi-lo)/2;
        if(jobs[mid][0] >= jobs[ind][1]) hi = mid-1;
        else lo = mid+1;
    } 
    return dp[ind] = max(ans, jobs[ind][2] + solve(lo, jobs));

}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<vector<int>> jobs;
        for(int i=0; i<profit.size(); ++i) {
            jobs.emplace_back(vector<int>{startTime[i], endTime[i], profit[i]});
        }
        sort(begin(jobs), end(jobs));
        memset(dp,-1,sizeof(dp));
        return solve(0, jobs);

    }
};