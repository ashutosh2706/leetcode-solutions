class Solution {
public:
    int DP[101][205];
    int solve(int ind, string &s, int val) {

        if(val < 0) return 0;
        if(ind == s.length()) return val == 0;
        if(DP[ind][val+101] != -1) return DP[ind][val+101];

        int ans = 0;
        if(s[ind] == '(') ans = solve(ind+1, s, val+1);
        else if(s[ind] == ')') ans = solve(ind+1, s, val-1);
        else {
            ans = ans or solve(ind+1, s, val+1) 
            or solve(ind+1,s,val-1) 
            or solve(ind+1,s,val);
        }   
        return DP[ind][val+101] = ans;
    }
    bool checkValidString(string s) {
        memset(DP, -1, sizeof(DP));
        return solve(0,s,0);
    }
};