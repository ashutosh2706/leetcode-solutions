class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cp = "";
        sort(strs.begin(), strs.end());
        int i = 0, n = strs.front().length();
        while(i < n) {
            if(strs[0][i] == strs[strs.size() - 1][i]) { cp+=strs[0][i++]; }
            else break;
        }
        return cp;
    }
};