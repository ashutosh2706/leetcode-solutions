class Solution {
public:
    int minFlips(string s) {
    s += s;
    int n = s.length(), m = s.length()/2;
    string alt1 = "", alt2 = "";
    for(int i=0; i<n; i++) 
        if(i%2 == 0) {
            alt1 += '0';
            alt2 += '1';
        } else {
            alt1 += '1';
            alt2 += '0';
        }
        
    int l = 0, ans = n;
    int diff1 = 0, diff2 = 0;
    for(int r=0; r<n; r++) {
        if(s[r] != alt1[r]) diff1++;
        if(s[r] != alt2[r]) diff2++;
        if(r - l + 1 > m) {
            if(alt1[l] != s[l]) diff1--;
            if(alt2[l] != s[l]) diff2--;

            l++;
        } 
        if(r - l + 1 == m) ans = min({ans, diff1, diff2});
    }
    return ans;
    }
};