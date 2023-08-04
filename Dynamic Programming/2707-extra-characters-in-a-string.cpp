class Solution {
public:
    int DP[51];
    int solve(int ind, string &s, vector<string> &dic) {

        if(ind >= s.length()) return 0;

        if(DP[ind] != -1) return DP[ind];
        int ans = 0;
        
        for(auto &word:dic) {
            int len = word.length();
            if(s.substr(ind, len) == word) {
                ans = max(ans, len + solve(ind+len, s, dic));
            }
        }
        ans = max(ans, solve(ind+1, s, dic));
        return DP[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(DP, -1, sizeof(DP));
        int len = s.length();
        return len - solve(0, s, dictionary);
    }
};