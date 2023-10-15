class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.length();
        string ans = "";
        for(int i=0; i<n; ++i) {
            
            string sub;
            int ck = 0;
            for(int j=i; j<n; ++j) {
                sub += s[j];
                ck += (s[j] == '1');
                if(ck == k) {
                    if(ans.size() == 0 or sub.size() < ans.size()) ans = sub;
                    else if(sub.size() == ans.size()) {
                        if(sub < ans) ans = sub;
                    }
                    break;
                }
            }
        }
        
        return ans;
        
    }
};