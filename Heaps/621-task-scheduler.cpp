class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    
    if(n == 0) return tasks.size();
    map<char, int> map;
    for(auto &c : tasks) map[c]++;
    priority_queue<pair<int, char>> pq;
    for(auto &p:map) pq.push(make_pair(p.second, p.first));
    int timer = 0;
    queue<pair<char, int>> q;
    while(!map.empty()) {

        while(!q.empty() and q.front().second==timer) {
            pq.push({map[q.front().first], q.front().first});
            q.pop();
        }
        if(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            map[p.second]--;
            if(map[p.second] == 0) 
                map.erase(p.second);
            else 
                q.push({p.second, timer + n +1});
        }
        timer++;
    }
    return timer;
    
    }
};