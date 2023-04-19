class Solution {
public:
    string convert(string s, int rows) {
    if(rows == 1) return s;
    vector<string> v(rows, "");

    int o = 0, p = 0;
    for(int i=0; i<s.length(); i++) {
        if(!o) {
            v[p++].push_back(s[i]);
            if(p == rows) {
                p = rows - 2;
                o=1;
            }
        } else {
            v[p--].push_back(s[i]);
            if(p < 0) {
                p = 1;
                o=0;
            }
        }
    }

    string res = "";
    for(auto &a:v) res += a;
    return res;
    
    }
};