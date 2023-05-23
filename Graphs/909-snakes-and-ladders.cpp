class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
    int n = board.size();
    unordered_map<int,int> map;
    int cnt = 1;
    for(int i=n-1, p = 0; i>=0; i--, p++) {
        if(p%2 == 0) {
            for(int j=0; j<n; j++) {
                if(board[i][j] != -1) map[cnt] = board[i][j];
                cnt++;
            }
        }else {
            for(int j=n-1; j>=0; j--) {
                if(board[i][j] != -1) map[cnt] = board[i][j];
                cnt++;
            }
        }
    }
    int curr = 1, steps = 1;
    set<int> vis;
    queue<int> q;
    for(int i=1; i<=6; i++) {
        if(curr + i <= n*n) {
            if(map.count(curr+i) == 0) q.push(curr+i);
            else q.push(map[curr+i]);
        }
    }
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int e = q.front(); q.pop();
            if(e == n*n) return steps;
            for(int i=1; i<=6; i++) {
                if(e+i<=n*n and vis.count(e+i)==0) {
                    if(map.count(e+i) == 0) q.push(e+i);
                    else q.push(map[e+i]);
                    vis.insert(e+i);
                }
            }
        }
        steps++;
    }
    return -1;
    }
};