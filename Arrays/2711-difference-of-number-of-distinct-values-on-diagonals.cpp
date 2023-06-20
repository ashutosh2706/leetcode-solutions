class Solution {
public:
    
    int getEle(int i, int j, vector<vector<int>>& grid) {
        unordered_set<int> set;
        int x = i-1, y = j-1;
        while(x >= 0 and y >= 0) {
            set.insert(grid[x--][y--]);
        }
        int u = set.size();
        set.clear();
        x = i+1, y = j+1;
        while(x < grid.size() and y < grid[0].size()) {
            set.insert(grid[x++][y++]);
        }
        return abs(u - (int)set.size());
    }
    
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        
        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> res(R, vector<int>(C));
        
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                res[i][j] = getEle(i,j,grid);
                
            }
        }
        return res;
    }
};