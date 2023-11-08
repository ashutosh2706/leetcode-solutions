class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.length(), ans = 1, i = 0, j = 1;
        for(; j<n; ++j) {
            if(s[j] != (1 + s[j-1])) {
                ans = max(ans, j-i);
                i = j;
            }
        }
        return ans = max(ans, j-i);
    }
};