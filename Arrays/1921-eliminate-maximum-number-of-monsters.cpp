class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    vector<pair<double,int>> times;
    for(int i=0; i<dist.size(); i++) {
        times.push_back({(double)dist[i]/speed[i], i});
    }

    sort(begin(times),end(times));
    int curr = 0, i = 0;
    for(; i<times.size(); i++) {
        
        int ind = times[i].second;
        int nd = dist[ind] - (curr*speed[ind]);
        if(nd <= 0) break;
        curr++;
    }
    return i;
    }
};