class Solution {
public:
    int vow(char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
    
    int beautifulSubstrings(string s, int k) {
        int ans = 0;   
        for(int i=0; i<s.length(); ++i) {
            int c = 0, v = 0;
            for(int j=i; j<s.length(); ++j) {
                if(vow(s[j])) v++;
                else c++;
                
                if(c == v and ((c*v)%k == 0)) ans++;
                
            }
        }
        return ans;
    }
};
