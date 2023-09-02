class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& art, vector<vector<int>>& dig) {
    set<pair<int,int>> set;
    for(auto &v:dig) {
        set.insert({v[0], v[1]});
    }
    int cnt = 0;
    for(auto &v : art) {
        int pcs = 0;
        for(int i=v[0]; i<=v[2]; ++i) {
            for(int j=v[1]; j<=v[3]; ++j) {
                if(set.count({i,j}) == 0) pcs++;
            }
        }
        if(pcs == 0) cnt++;
    }
    return cnt;
    }
};