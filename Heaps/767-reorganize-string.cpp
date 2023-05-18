class Solution {
public:
    string reorganizeString(string s) {
        
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> map;
        for(auto &c:s) map[c]++;
        for(auto &p:map) pq.push({p.second, p.first});
        int time = 0;
        string res = "";
        queue<pair<int, char>> q;
        while(!pq.empty() or !q.empty()) {
            if(!q.empty() and q.front().first == time) {
                pq.push({map[q.front().second], q.front().second});
                q.pop();
            }
            if(pq.empty()) return "";
            auto p = pq.top(); pq.pop();
            res.push_back(p.second);
            map[p.second]--;
            if(map[p.second] > 0) {
                q.push({time+2, p.second});
            }
            time++;
        }
        return res;
        
    }
};