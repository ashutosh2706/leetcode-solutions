class Solution {
public:
    int equalSubstring(string s, string t, int total) {
        
    int l = 0, len = 0, n = s.length();
    long cost = 0;
    for(int r = 0; r < n; r++) {
        cost += abs(s[r] - t[r]);
        while(l <= r && cost > total) {
            cost -= abs(s[l] - t[l]);
            l++;
        }
        len = max(len, r-l+1);

    }
    return len;
    }
};