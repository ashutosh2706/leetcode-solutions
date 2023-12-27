class Solution {
public:
    int minCost(string colors, vector<int>& time) {

    int n = colors.length(), ans = 0;
    for(int i=0; i<n;) {
        priority_queue<int, vector<int>, greater<int>> pq;
        char col = colors[i];
        while(i < n and colors[i] == col) {
            pq.push(time[i]);
            i++;
        }

        while(pq.size() > 1) {
            ans += pq.top();
            pq.pop();
        }
    }
    return ans;
    }
};