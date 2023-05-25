class Solution {
private:
int tarverse(int x, int y, pair<int, int> &p, vector<vector<char>>& grid, char col) {
    int cnt = 0;
    while(x<8 and y<8 and x>=0 and y>=0) {
        if(grid[x][y] == col) return cnt>=2;
        if(grid[x][y] == '.' and cnt > 0) return 0;
        cnt++;
        x+=p.first;
        y+=p.second;
    }
    return 0;
}
public:
    bool checkMove(vector<vector<char>>& grid, int r, int c, char col) {

    vector<pair<int,int>> dirs {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        for(auto &p:dirs) {
            if(tarverse(r,c,p,grid,col)) return 1;
        }
        return 0;
    }
};