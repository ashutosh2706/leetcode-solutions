class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i=0; i<m; i++) {
            if(grid[i].front() < 0) ans += n;
            else
                ans += lower_bound(grid[i].rbegin(), grid[i].rend(), 0) - grid[i].rbegin();
        }
        return ans;
    }
};