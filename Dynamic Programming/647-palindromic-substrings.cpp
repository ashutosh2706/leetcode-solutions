class Solution {
public:
    int countSubstrings(string s) {
int len = s.length();
        int ans = 0;
        for(int i=0; i<len; i++) {
            int l=i, r=i;
            while((l>=0 && r<len) && s[l]==s[r]) {
                ans++;
                l--; r++;
            }
            l = i, r=i+1;
            while((l>=0 && r<len) && s[l]==s[r]) {
                ans++;
                l--; r++;
            }
        }
        return ans;
    }
};