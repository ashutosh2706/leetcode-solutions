class Solution {
public:
    unordered_map<int, vector<int>> mp;
    void solve(int ind, vector<int> &res, int s) {
        res[ind] = s;
        for(auto &p : mp[s]) {
            if(ind == 0) solve(ind+1, res, p);
            else {
                if(p != res[ind-1]) 
                    solve(ind+1, res, p);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto &v : adjacentPairs) {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        int s;
        for(auto &p : mp) if(p.second.size() == 1) { s=p.first; break; }
        vector<int> res((int)mp.size());
        solve(0, res, s);
        return res;
    }
};