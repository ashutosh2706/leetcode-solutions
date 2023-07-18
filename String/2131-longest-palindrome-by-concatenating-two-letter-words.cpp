class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int map[26][26] = {0}, ans = 0;
        for(auto &s:words) {
            int a = s[0] - 'a';
            int b = s[1] - 'a';

            if(map[b][a]) {
                ans += 4;
                map[b][a]--;
            }else 
                map[a][b]++;
        }

        for(int i=0; i<26; i++) {
            if(map[i][i]) return ans + 2;
        }
        
        return ans;
    }
};