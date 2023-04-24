class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
    map<char, string> mp;
    unordered_set<string> st;
    stringstream ss(s);
    string token;
    int i = 0;
    while(getline(ss, token, ' ')) {
        if(i == pattern.length()) return 0;
        if(mp.count(pattern[i]) == 0) {
            if(st.count(token)) return 0;
            mp[pattern[i]] = token;
            st.insert(token);
        } else {
            if(mp[pattern[i]] != token) return 0;
        }
        i++;
    }

    if(i < pattern.length()) return 0;
    return 1;

    }
};