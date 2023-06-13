class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        map<vector<int>, int> set;
        for(int i=0; i<col; i++) {
            vector<int> v;
            for(int r=0; r<row;) v.push_back(grid[r++][i]);
            set[v]++;
        }
        int ans = 0;
        for(int i=0; i<row; i++) {
            vector<int> v;
            for(int c=0; c<col;) v.push_back(grid[i][c++]);
            ans += set[v]; 
        }
        return ans;
    }
};