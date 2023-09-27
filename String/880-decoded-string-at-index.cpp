class Solution {
public:
    char ans = ' ';
    void solve(int rem, string &s) {

        int cnt = 0;
        for(auto &c:s) {
            int f = 0;
            if(isalpha(c)) {
                cnt++;
            } else {
                int i=0;
                while(i < (c-'0') and cnt*(i+1) < rem) ++i;
                if(i == (c-'0')) {
                    cnt *= i;
                } else {
                    solve(rem - (cnt*i),s);
                    break;
                }
            }
            if(cnt == rem) {
                if(ans == ' ') ans = c;
                return;
            }
        }
    }
    string decodeAtIndex(string s, int k) {
        solve(k,s);
        string r;
        r+=ans;
        return r;        
    }
};