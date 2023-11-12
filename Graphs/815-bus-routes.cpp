class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<routes.size(); ++i) {
            for(auto &a : routes[i]) {
                mp[a].push_back(i);
            }
        }

        queue<int> q;
        q.push(source);
        int steps = 0;
        unordered_set<int> bus,stops;
        stops.insert(source);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int t = q.front(); q.pop();
                if(t == target) return steps;
                for(auto &b : mp[t]) {
                    if(!bus.count(b)) {
                        bus.insert(b);
                        for(auto &r : routes[b]) {
                            if(!stops.count(r)) {
                                stops.insert(r);
                                q.push(r);
                            }
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};