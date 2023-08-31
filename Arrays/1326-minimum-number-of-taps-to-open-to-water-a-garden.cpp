class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dist(n+1);
        for(int i=0; i<ranges.size(); ++i) {
            int start = max(0, i-ranges[i]);
            int end = min(n, ranges[i]+i);
            dist[start] = max(dist[start], end);
        }

        int taps=0, ce = 0, me = 0;
        for(int i=0; i<=n; ++i) {
            if(i > me) return -1;

            if(i > ce) {
                ce = me;
                taps++;
            }
            me = max(me, dist[i]);
        }
        return taps;
    }
};