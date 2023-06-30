// BFS + BitMasking
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        
        int R = grid.size(), C = grid[0].length();

        int total = 0, vis[R][C][100], moves = 0;
        memset(vis,0,sizeof(vis));

        queue<vector<int>> q;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(grid[i][j] == '@') {
                    q.push({i,j,0});
                    vis[i][j][0] = 1;
                    continue;
                }
                if(grid[i][j] >= 'A' and grid[i][j] <= 'F') {
                    total |= 1 << (grid[i][j] - 'A');
                }
            }
        }


        vector<vector<int>> dirs {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {

                int x = q.front()[0], y = q.front()[1], key = q.front()[2];
                q.pop();
                
                if(key == total) return moves;
                
                for(auto& dir : dirs) {

                    int nx = x+dir[0];
                    int ny = y+dir[1];

                    if(nx >= 0 and nx < R and ny >= 0 and ny < C and grid[nx][ny] != '#') {

                        char ch = grid[nx][ny];
                        if(!vis[nx][ny][key] and ch >= 'a' and ch <= 'f') {

                            int new_key = key | (1 << (ch - 'a'));
                            vis[nx][ny][new_key] = 1;
                            q.push({nx,ny,new_key});

                        } else if(!vis[nx][ny][key] and ch >= 'A' and ch <= 'Z') {

                            if(key & (1 << (ch - 'A'))) {
                                // unlock
                                q.push({nx,ny,key});
                                vis[nx][ny][key] = 1;
                            }
                        } else {

                            if(!vis[nx][ny][key]) {
                                q.push({nx,ny,key});
                                vis[nx][ny][key] = 1;
                            }
                        }
                    }
                }
            }

            moves++;

        }

        return -1;

    }
};