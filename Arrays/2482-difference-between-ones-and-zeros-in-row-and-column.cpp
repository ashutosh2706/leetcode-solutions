class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int r = grid.size(), c = grid[0].size();
    vector<int> rc(r), cc(c);
    for(int i=0; i<r; i++) {
        int cnt = 0;
        for(int j=0; j<c; ++j) {
            if(grid[i][j]) cnt++;
        }
        rc[i] = cnt;
    }

    for(int i=0; i<c; ++i) {
        int cnt = 0;
        for(int j=0; j<r; ++j) {
            if(grid[j][i]) cnt++;
        }
        cc[i] = cnt;
    }

    vector<vector<int>> res(r, vector<int>(c));
    for(int i=0; i<r; ++i) {
        for(int j=0; j<c; ++j) {
            res[i][j] = rc[i] + cc[j] - (c - rc[i]) - (r - cc[j]);
        }
    }
    return res;
    }
};