class Solution {
public:
    bool splitString(string s) {
        return solve(0, s, -1);
    }

    int solve(int ind, string &s, long long prev) {
        if(ind == s.length()) return 1;

        bool b = 0;
        for(int i=ind; i<s.length(); i++) {

            long long x = stoll(s.substr(ind, i-ind+1));

            if(x >= 1e12) break;
            if(prev == -1 and i == s.length()-1) break;

            if(prev == -1 or (x == prev-1)) {
                b = b or solve(i+1, s, x);
            }
        }
        return b;
    }
};