class Solution {
public:
    vector<int> par, sz;
    int findPar(int n) {
        if(par[n] == n) return n;
        return par[n] = findPar(par[n]);
    }

    void Union(int n1, int n2) {
        n1 = findPar(n1);
        n2 = findPar(n2);

        if(n1 == n2) return;

        if(sz[n1] > sz[n2]) {
            par[n2] = n1;
            sz[n1] += sz[n2];
        } else {
            par[n1] = n2;
            sz[n2] += sz[n1];
        }


    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        par.resize(s.length());
        sz.resize(s.length(),1);
        for(int i=0; i<s.length(); ++i) {
            par[i]=i;
        }

        for(auto &p : pairs) {
            Union(p[0], p[1]);
        }

        map<int, map<char, int>> cnt;
        for(int i=0; i<s.length(); ++i) {
            cnt[findPar(i)][s[i]]++;
        }

        string res(s.length(), ' ');
        for(int i=0; i<s.length(); ++i) {
            int p = findPar(i);
            char c = begin(cnt[p])->first;
            res[i] = c;
            if(--cnt[p][c] == 0) cnt[p].erase(c);
        }

        return res;
    }
};
