class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.size() + 1, 1e9);
    dp[days.size()] = 0;
    for(int i=days.size()-1; i>=0; i--) {
        for(int j=0; j<3; j++) {
            if(j == 0) {
                auto it = lower_bound(days.begin()+i, days.end(), days[i]+1);
                dp[i] = min(dp[i], costs[j] + dp[it-days.begin()]);
            }
            else if(j == 1) {
                auto it = lower_bound(days.begin()+i, days.end(), days[i]+7);
                dp[i] = min(dp[i], costs[j] + dp[it-days.begin()]);
            } else {
                auto it = lower_bound(days.begin()+i, days.end(), days[i]+30);
                dp[i] = min(dp[i], costs[j] + dp[it-days.begin()]);
            }
        }
    }
    return dp[0];
    }
};