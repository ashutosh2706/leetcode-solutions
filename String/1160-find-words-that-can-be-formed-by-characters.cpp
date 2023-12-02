class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> v(26);
        for(auto &a : chars) {
            v[a-'a']++;
        }
        int cnt=0;
        for(auto &w : words) {
            bool b = 1;
            vector<int> vc(26);
            for(auto &c : w) vc[c-'a']++;
            for(int i=0; i<26; ++i) {
                if(vc[i] > 0) {
                    if(vc[i] > v[i]) { b=0; break; }
                }
            }
            if(b) cnt += w.length();
        }
        return cnt;
    }
};
