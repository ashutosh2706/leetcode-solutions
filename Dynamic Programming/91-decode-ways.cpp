class Solution {
private:
    int f(int ind, string &s, vector<int> &dp) {
        if(ind == s.length()-1 && s[ind] == '0') return 0;
        else if(ind == s.length() || ind == s.length()-1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int l=0, r=0;
        if(s[ind]!='0') l = f(ind+1, s, dp);
        int ss = stoi(s.substr(ind, 2));
        if(ss >= 10 && ss <=26) r = f(ind+2, s, dp);
        return dp[ind] = l+r;
    }
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        vector<int> dp(s.length() + 1, -1);
        return f(0, s, dp);
    }
};