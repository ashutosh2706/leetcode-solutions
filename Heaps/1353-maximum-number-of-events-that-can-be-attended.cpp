class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(begin(events),end(events));
        int ans = 0, i = 0;
        for(int d=1; d <= 100001; ++d) {
            while(!pq.empty() and pq.top() < d) pq.pop();
            while(i < events.size() and events[i][0] == d) {
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};