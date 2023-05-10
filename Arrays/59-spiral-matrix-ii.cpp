class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        auto isvalid = [](int x, int y, int &n) {
            if(x < 0 or y < 0 or x >= n or y >= n) return 0;
            return 1;
        };
        
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<pair<int, int>> dirs {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int ind = 0, cnt = 2;
        int r = 0, c = 0;
        matrix[0][0] = 1;
        if(n == 1) return matrix;
        while(cnt <= n*n) {
            int x = dirs[ind%4].first, y = dirs[ind%4].second;
            if(isvalid(x+r, y+c, n) and matrix[x+r][y+c] == 0) {
                matrix[r+x][y+c] = cnt++;
                r+=x;
                c+=y;
            } else ind++;
        }
        return matrix;
       
    }
};