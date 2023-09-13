class Solution {
public:
    int numMatchingSubseq(string &s, vector<string>& words) {
    unordered_map<char, vector<int>> map;
    for(int i=0; i<s.length(); i++) {
        map[s[i]].push_back(i);
    }
    unordered_set<string> set;
    int cnt = 0;
    for(auto &w : words) {
        if(set.count(w)) {
            cnt++;
            continue;
        }
        int prev = -1, b = 1;
        for(auto &c : w) {
            vector<int> v = map[c];
            auto it = upper_bound(begin(v), end(v), prev);
            if(it == end(v)) { b = 0; break; }
            else prev = *it;
        }
        if(b) set.insert(w);
        cnt += b;
    }
    return cnt;
    }
};