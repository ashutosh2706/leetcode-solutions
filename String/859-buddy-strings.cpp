class Solution {
public:
    bool buddyStrings(string s1, string s2) {
    if(s1.length() != s2.length() or s1.length() == 1) return 0;

    vector<int> v;
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] != s2[i]) {
            v.push_back(i);
        }
    }

    if(v.size() > 0) {
        if(v.size() != 2) return 0;
        else return (s1[v[0]] == s2[v[1]] and s1[v[1]] == s2[v[0]]);
    }else {
        unordered_set<char> s;
        for(auto& c:s1) {
            if(s.count(c)) return 1;
            else s.insert(c);
        }
    }
    return 0;
    }
};