class Solution {
public:
int dp[1001][26][26];

int solve(int ind, vector<string> &words, char f, char b) {
    if(ind >= words.size()) return 0;
    if(dp[ind][f-'a'][b-'a'] != -1) return dp[ind][f-'a'][b-'a'];
    int ans = 0;
    if(words[ind].back() == f) 
        ans = max(ans, 1 + solve(ind+1, words, words[ind].front(),b));

    if(words[ind].front() == b) 
        ans = max(ans, 1+solve(ind+1, words, f, words[ind].back()));

        ans = max({solve(ind+1, words, f, words[ind].back()), 
            solve(ind+1, words, words[ind].front(), b), ans});
    return dp[ind][f-'a'][b-'a'] = ans;
}

    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        int len = 0;
        for(auto &s : words) len += s.length();
        return (len - solve(1, words, words[0].front(), words[0].back()));    
    }
};