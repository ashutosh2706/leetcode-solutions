class Solution {
public:
    int numTrees(int n) {
        // Question is asking to calculate the nth catalan number
        // For calculating the nth catalan number :
        // C[n] = C[0]*C[n-1] + C[1]*C[n-2] + C[2]*C[n-3] + ...... + C[n-2]*C[1] + C[n-1][0]
        
        vector<int> cat(n+1);
        cat[0] = cat[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int j=0; j<i; j++) {
                cat[i] += cat[j] * cat[i-1-j];
            }
        }
        return cat[n];  // the n-th catalan number
    }
};