class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        
        unordered_set<int> row,col;
        long long sum = 0;
        for(int i=queries.size()-1; i>=0; i--) {
            int type = queries[i][0], ind = queries[i][1], val = queries[i][2];
            if(type == 0) {
                if(row.count(ind) == 0) {
                    sum += (n - (int)col.size()) * val;
                    row.insert(ind); 
                }
            } else {
                if(col.count(ind) == 0) {
                    sum += (n - (int)row.size()) * val;
                    col.insert(ind); 
                }
            }
        }
        return sum;
    }
};