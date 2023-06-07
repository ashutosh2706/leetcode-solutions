class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i=0; i<=31; i++) {
            int ba = (a >> i) & 1;
            int bb = (b >> i) & 1;
            int bc = (c >> i) & 1;
        
            if(bc == (ba or bb)) continue;
            if(bc) ans += 1;
            else (bb and ba) ? ans += 2 : ans += 1;
        }
        return ans;
    }
};