class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
    map<string, int> map1;
    for(auto &s : words) map1[s]++;
    map<int, vector<string>> map2;
    for(auto &p : map1) map2[p.second].push_back(p.first);
    vector<string> res;
    for(auto it = map2.rbegin(); it != map2.rend(); it++) {
        vector<string> V = it->second;
        for(int i=0; i<V.size() and res.size() < k; i++) 
            res.push_back(V[i]);

        if(res.size() == k) break;
    }
    return res;
    }
};