class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<pair<int,int>> dirs {{0,1},{1,0},{0,-1},{-1,0}};
        int ptr = 0, x = 0, y = -1;
        while(head) {
            ptr%=4;
            int i = dirs[ptr].first, j = dirs[ptr].second;
            x+=i; y+=j;
            while(head) {
                matrix[x][y] = head->val;
                head = head->next;
                if(x + i == m or y + j == n or x + i < 0 or y + j < 0 or matrix[x+i][y+j] != -1) break;
                else {
                    x+=i;
                    y+=j;
                }
            }
            ptr++;
        }
        return matrix;
    }
};