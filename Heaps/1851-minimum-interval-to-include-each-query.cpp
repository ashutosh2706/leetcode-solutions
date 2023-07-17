class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    sort(begin(intervals),end(intervals));
    unordered_map<int,vector<int>> map;

    for(int i=0; i<queries.size(); i++) {
        map[queries[i]].push_back(i);
    }
    vector<int> res(queries.size());
    sort(queries.begin(), queries.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int l=0, i=0; i<queries.size(); i++) {


        while(l < intervals.size() and intervals[l][0] <= queries[i]) {
            pq.push({intervals[l][1] - intervals[l][0] + 1, intervals[l][1]});
            l++;
        }

        while(pq.size() and pq.top().second < queries[i]) {
            pq.pop();
        }

        for(auto &p : map[queries[i]]) {
            if(pq.empty()) res[p] = -1;
            else res[p] = pq.top().first;
        }
    }
    return res;
    }
};