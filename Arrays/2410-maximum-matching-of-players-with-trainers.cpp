class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &a:trainers) pq.push(a);
        int cnt = 0;
        sort(begin(players), end(players));
        for(auto &p : players) {
            while(!pq.empty() and pq.top() < p) pq.pop();
            if(!pq.empty() and pq.top() >= p) {
                cnt++;
                pq.pop();
            }
        }
        return cnt;
    }
};