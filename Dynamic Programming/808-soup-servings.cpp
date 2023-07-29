class Solution {
public:
    double soupServings(int n) { 
        if(n >= 4800) return 1;
        dp.resize(n+1, vector<double>(n+1, -1.0));
        return solve(n,n);
    }
    
    vector<vector<double>> dp;
    double solve(int a, int b) {
        
        if(a <= 0 and b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;

        if(dp[a][b] != -1) return dp[a][b];

        double ans = 0.0;

        for(int i=100; i>=25; i-=25) {
            int na = max(0, i);
            int nb = max(0, (100-i));
            ans += 0.25*solve(a-na,b-nb);
        }

        return dp[a][b] = ans;
    }
};