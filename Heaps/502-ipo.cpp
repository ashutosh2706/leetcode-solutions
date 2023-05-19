class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& cost) {
        
        vector<pair<int,int>> v;
        for(int i=0; i<profit.size(); i++) {
            v.push_back({cost[i], profit[i]});
        }
        sort(begin(v), end(v));
        priority_queue<int> pq;
        for(int i=0, j=0; i<k; i++) {

            while(j<v.size() and v[j].first<=w) {
                pq.push(v[j++].second);
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};