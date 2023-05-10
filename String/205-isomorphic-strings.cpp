class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.length() != t.length()) return 0;
        int n = s.length();
        map<char, char> maps, maps2;
        for(int i=0; i<n; i++) {
            if(maps.find(s[i]) == maps.end() and maps2.find(t[i]) == maps2.end()) {
                maps[s[i]] = t[i];
                maps2[t[i]] = s[i];
            } else {
                if(maps[s[i]] == t[i] and maps2[t[i]] == s[i]) continue;
                else return 0;
            }
        }
        return 1;
    }
};