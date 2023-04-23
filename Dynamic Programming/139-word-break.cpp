class Solution {
private:
    bool f(int ind, string s, vector<string> &dic, vector<int> &dp) {
        if(ind == s.length()) return true;
        else if(ind > s.length()) return false;
        if(dp[ind] != -1) return dp[ind];
        bool ff = false;
        for(string ss:dic) {
            int len = ss.length();
            if(ss == s.substr(ind, len)) {
                ff = f(ind+len, s, dic, dp);
                if(ff) break;
            }
        }
        return dp[ind] = ff;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), -1);
        return f(0, s, wordDict, dp);
    }
};