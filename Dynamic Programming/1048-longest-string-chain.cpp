class Solution {
public:
    bool isChain(string a, string b) {
        if(a.length() == b.length()) return 0;
        if((b.length() - a.length()) > 1) return 0;
        int cnt = 0, i1 = 0, i2 = 0;
        while(i1 < a.length() and i2 < b.length()) {
            if(a[i1] == b[i2]) {
                i1++;
                i2++;
            }else {
                i2++;
                cnt++;
            }
            if(cnt >= 2) break;
        }
        return cnt < 2;
    }

    int longestStrChain(vector<string>& words) {
        sort(begin(words), end(words), [](string &a, string &b){
            return a.length() < b.length();
        });  
        int ans = 1;
        vector<int> dp(words.size()+1, 1);
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<i; ++j) {
                if(isChain(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};