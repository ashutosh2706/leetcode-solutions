class Solution {
private:

bool find(int i, int j, int x, vector<vector<char>> &grid, string &word) {

    if(x == word.length()) return 1;

    if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) return 0;

    bool b = 0;
    if(grid[i][j] == word[x]) {
        char c = '.';
        swap(c, grid[i][j]);
        b = find(i + 1, j, x+1, grid, word) || b;
        b = find(i-1,j,x+1,grid,word) || b;
        b = find(i,j+1,x+1,grid,word) || b;
        b = find(i,j-1,x+1,grid,word) || b;

        swap(c, grid[i][j]);
    }

    return b;
}

public:
    bool exist(vector<vector<char>>& grid, string word) {
    
    int f = 0;
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) 
            if(grid[i][j] == word[0]) if(find(i,j,0,grid,word)) return 1;
    }
    return 0;
    }
};