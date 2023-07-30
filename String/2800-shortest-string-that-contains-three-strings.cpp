class Solution {
public:
    int len(string &a, string &b) {

        int n1 = a.length(), n2 = b.length();
        for(int i1=0, i2=0; i1 < n1; i1++) {
            int len = min(n1 - i1, n2);
            string s1 = a.substr(i1, len), s2 = b.substr(0, len);
            if(s1 == s2) return len;
        }
        return 0;

    }
    string minimumString(string a, string b, string c) {

        vector<vector<string>> perm {{a,b,c},{a,c,b},{b,a,c},{b,c,a},{c,a,b},{c,b,a}};
        vector<string> ans;
        for(auto &vec : perm) {
            string res = vec[0];
            for(int i=1; i<3; i++) {
                int le = len(res, vec[i]);
                res += vec[i].substr(le);
            }
            ans.push_back(res);
        }    
        
        sort(begin(ans), end(ans), [](string &a, string &b){
            if(a.length() != b.length()) {
                return a.length() < b.length();
            } 
            return a < b;
        });
        return ans[0];

    }
};