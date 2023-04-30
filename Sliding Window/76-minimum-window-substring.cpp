class Solution {
public:
    string minWindow(string s, string t) {   
    vector<int> v(128, 1e9);
    int req = 0, n = s.length();
    for(auto &c : t) {
        if(v[c] == 1e9) v[c] = 1;
        else v[c]++;
        req++;
    }
    int l = 0, len = -1;
    int R,L;
    for(int r = 0; r < n; r++) {
        if(v[s[r]] == 1e9) continue;
        if(v[s[r]] > 0) req--;
        v[s[r]]--;
        while(l <= r && req == 0) {
            if(v[s[l]] == 1e9) { l++; continue; }
            if(len == -1 || ((r-l+1) < len)) {
                len = r - l + 1;
                R = r;
                L = l;
            }
            if(v[s[l]] >= 0) req++;
            v[s[l++]]++; 
        }
    }
    return (len <= 0) ? "" : s.substr(L, R-L+1);
    }
};