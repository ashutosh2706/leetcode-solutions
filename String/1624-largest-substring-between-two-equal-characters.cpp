class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v(26, -1);
        for(int i=0; i<s.length(); ++i) {
            v[s[i]-'a']=i;
        }
        int ans = -1;
        for(int i=0; i<s.length(); ++i) {
            if(v[s[i]-'a'] != -1 and v[s[i] - 'a'] != i) {
                ans = max(ans, v[s[i]-'a'] - i -1);
            }
        }
        return ans;
    }
};