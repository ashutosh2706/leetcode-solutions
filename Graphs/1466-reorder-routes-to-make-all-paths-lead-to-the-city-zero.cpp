class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        map<int,vector<pair<int,int>>> map;
    for(auto &vec:conn) {
        map[vec[0]].push_back({vec[1], 1});
        map[vec[1]].push_back({vec[0], 0});
    }
    vector<int> vis(n+1); 
    int ans = 0;
    //deb(map)
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int node = q.front(); q.pop();
            for(auto &a : map[node])
                if(!vis[a.first]) {
                    q.push(a.first);
                    vis[a.first] = 1;
                    if(a.second) ans++; 
                }
        }
    }
    return ans;
    }
};