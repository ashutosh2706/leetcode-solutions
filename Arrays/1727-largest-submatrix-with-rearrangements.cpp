class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int max_area=0;
         int m=matrix.size();
        int n=matrix[0].size();
               vector<int>prev_row(n,0);
        for(int row=0;row<m;row++){
            vector<int>curr_row=matrix[row];
            for(int col=0;col<n;col++){
                if(curr_row[col]==1){
                    curr_row[col]+=prev_row[col];
                }
            }
            vector<int>heights=curr_row;
            sort(begin(heights),end(heights),greater<int>());
            for(int i=0;i<n;i++){
                int base=(i+1);
                int height=heights[i];
                max_area=max(max_area,base*height);
            }
            prev_row=curr_row;
        }
        return max_area;
    }
};
