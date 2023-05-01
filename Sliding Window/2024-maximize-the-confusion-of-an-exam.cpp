class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int t = 0, f = 0, l = 0, ans = 0;
        for(int r = 0; r < s.length(); r++) {
            if(s[r] == 'T') t++;
            else f++;
            while(min(t,f) > k) {
                if(s[l] == 'T') t--;
                else f--;
                l++; 
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};