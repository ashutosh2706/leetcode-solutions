class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto &q : queries) {
            int p = 0;
            for(auto &c : q) {
                if(c >= 'A' and c <= 'Z') {
                    if(p == pattern.length() or pattern[p] != c) { p =0; break; }
                    else ++p;
                    continue;
                } else if(c == pattern[p]) ++p;
            }
            ans.push_back(p == pattern.length());
        }
        return ans;
    }
};