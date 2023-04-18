// Tricky One

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        
    int n = grid[0].size();
    vector<vector<long long>> t(2, vector<long long> (n+1));

    long long res = LLONG_MAX, x, y;
    for(int i=n-1; i>=0; i--) {
        t[0][i] = grid[0][i] + t[0][i+1];
        t[1][i] = grid[1][i] + t[1][i+1];
    }

    for(int i=0; i<n; i++) {
        x = 0, y = 0;
        if(i+1 < n) x = t[0][i+1];
        y = t[1][0] - t[1][i];
        res = min(res, max(x,y));
    }
    return res;
    }
};