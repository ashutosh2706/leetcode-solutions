class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
    int ln = logs.size();
    sort(begin(logs), end(logs), [](vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    });
    unordered_map<int,int> map, m2;
    for(int i=0; i<queries.size(); i++) map[queries[i]] = i;
    sort(begin(queries), end(queries));
    vector<int> res(queries.size());
    int l = 0, r = 0;
    for(auto &q:queries) {
        while(r < ln and logs[r][1] <= q) {
            m2[logs[r++][0]]++;
        }
        while(l < ln and logs[l][1] < (q-x)) {
            if(--m2[logs[l][0]] == 0) 
                m2.erase(logs[l][0]);
            l++;
        }
        res[map[q]] = n - (int)m2.size();
    }
    return res;
    }
};