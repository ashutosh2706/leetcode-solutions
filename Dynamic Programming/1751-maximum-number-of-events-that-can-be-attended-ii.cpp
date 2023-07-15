class Solution {
public:
    vector<vector<int>> dp;
    int solve(int ind, int k, vector<vector<int>> &events) {
        if(ind >= events.size() or  k==0) return 0;

        if(dp[ind][k] != -1) return dp[ind][k];
        int skip = solve(ind+1, k, events);
        int x = ind+1;
        for(; x<events.size(); ++x) {
            if(events[x][0] > events[ind][1]) {
                break;
            }
        }
        int take = events[ind][2] + solve(x, k-1, events);
        return dp[ind][k] = max(take, skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events), [](vector<int>&a, vector<int>&b) {
            return a[0] < b[0];
        });
        dp.resize(events.size()+1, vector<int>(k+1, -1));
        return solve(0, k, events);

    }
};