class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string s1 = "0", s2 = "1";
        for(int i=1; i<n; ++i) {
           if(s1.back() == '0') s1.push_back('1');
           else s1.push_back('0');
           if(s2.back() == '0') s2.push_back('1');
           else s2.push_back('0');
        }
        cout << s1 << endl << s2;
        int cnt1=0, cnt2=0;
            for(int i=0; i<n; ++i) {
                if(s[i] != s1[i]) ++cnt1;
                if(s[i] != s2[i]) ++cnt2;
            }
        return min(cnt1, cnt2);
    }
};