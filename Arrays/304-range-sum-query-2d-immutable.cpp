class NumMatrix {
public:
    int R, C;
    vector<vector<int>> M;
    NumMatrix(vector<vector<int>>& matrix) {
        R = matrix.size(), C = matrix[0].size();
        
        for(int i=0; i<R; i++) {
            for(int j=C-2; j>=0; j--)
                matrix[i][j] += matrix[i][j+1];
        }

        for(int j=0; j<C; j++) {
            for(int i=R-2; i>=0; i--)
                matrix[i][j] += matrix[i+1][j];
        }

        M = matrix;    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int x, y;
        if(col2 == C-1) x = 0;
        else x = M[row1][col2+1];

        if(row2 == R-1) y = 0;
        else {
            if(col2 == C-1) y = M[row2+1][col1];
            else y = M[row2+1][col1] - M[row2+1][col2+1];
        }
        return M[row1][col1] - (x+y);
    }
};