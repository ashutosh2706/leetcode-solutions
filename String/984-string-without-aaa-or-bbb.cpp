class Solution {
public:
    string strWithout3a3b(int a, int b) {
        if(b < a) {
            string ans = strWithout3a3b(b ,a);
            for(int i=0; i<ans.length(); i++) {
                if(ans[i] == 'a') ans[i] = 'b';
                else ans[i] = 'a';
            }
            return ans;
        }
        
        string res;
        if(b > 2*a) res += string(b - 2*a, 'b');
        b -= res.length();
        int d = b-a;
        while(a > 0) {
            res += "ab";
            a -= 1;
            if(d > 0) {
                res += 'b';
                d--;
            }
        }
        return res;
    }
};