class Solution {
public:
    bool equalFrequency(string s) {
    vector<int> f(26);
    for(auto&c : s) f[c-'a']++;
    for(int i=0; i<26; i++) {
        if(f[i] == 0) continue;
        f[i] -= 1;
        bool b = 1;
        int cnt = -1;
        for(int j=0; j<26; j++) {
            if(f[j] > 0) {
                if(cnt == -1) cnt = f[j];
                else {
                    if(cnt != f[j]) {
                        b = 0;
                        break;
                    }
                }
            }
        }
        if(b) return 1;
        f[i] += 1;
    }
    return 0;
    }
};