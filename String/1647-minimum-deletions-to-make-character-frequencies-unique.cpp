class Solution {
public:
    int minDeletions(string s) {
    vector<int> f(26);
    for(auto &c:s) f[c-'a']++;
    unordered_map<int,int> map;
    for(auto &a:f) if(a > 0) map[a]++;
    priority_queue<pair<int,int>> pq;
    for(auto &p : map) {
        pq.push({p.first, p.second});
    }
    int ans = 0;
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        if(p.second == 1 || p.first == 0) continue;
        ans += (p.second-1);
        if(pq.size() > 0 and (pq.top().first == p.first-1)) {
            auto c = pq.top(); pq.pop();
            pq.push({c.first, c.second+(p.second-1)});
        } else {
            pq.push({p.first-1, p.second-1});
        }
    }
    return ans;
    }
};
