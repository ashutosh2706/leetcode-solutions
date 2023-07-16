class Solution {
public:
    int DP[101][51][51];
    int solve(int ind, vector<vector<int>>& costs, int A, int B) {
        if(ind == costs.size()) return 0;
        if(DP[ind][A][B] != -1) return DP[ind][A][B];
        int ans;
        if(A > 0 and B > 0) {
            ans = min(costs[ind][0] + solve(ind+1, costs, A-1,B), costs[ind][1] + 
                solve(ind+1, costs, A, B-1));
        } else if(A > 0) {
            ans = costs[ind][0] + solve(ind+1, costs, A-1, B);
        } else 
            ans = costs[ind][1] + solve(ind+1, costs, A, B-1);

        return DP[ind][A][B] = ans;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size();
        memset(DP, -1, sizeof(DP));
        return solve(0, costs, N/2, N/2);
    }
};