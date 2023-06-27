class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();
        priority_queue<int> pq;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(pq.size() < k) {
                    pq.push(matrix[i][j]);
                    continue;
                }

                if(pq.top() > matrix[i][j]) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                } else break;
            }
        }
        return pq.top();
    }
};