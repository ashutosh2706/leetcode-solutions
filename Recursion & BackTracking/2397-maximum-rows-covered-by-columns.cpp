class Solution {
public:
    int getcover(int& mask, vector<vector<int>>& mat) {
        int c = 0;
        int R = mat.size(), C = mat[0].size();
        for(int i=0; i<R; i++) {
            bool b = 1;
            for(int j=0; b and j<C; j++) {
                if(mat[i][j] and (mask & (1<<j)) == 0) b = 0;
            }
            c += b;
        }
        return c;
    }
    int solve(int ind, int select, int& col, int mask, vector<vector<int>>& mat) {

        if(select == 0) return getcover(mask, mat);
        if(ind == col) return 0;
        int ans = 0;
        if((mask & (1<<ind)) == 0) {
            ans = max(ans, solve(ind+1, select-1, col, mask | (1<<ind), mat));
        }
        ans = max(ans, solve(ind+1, select, col, mask, mat));
        return ans;
    }

    int maximumRows(vector<vector<int>>& matrix, int select) {
        int C = matrix[0].size();
        return solve(0, select, C, 0, matrix);
    }
};