class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> map;
        int ans = 0, l = 0, r = 0, maxf = 0;
        while(r < s.length()) {

            map[s[r++]]++;
            maxf = max(maxf, map[s[r-1]]);
            if(r - l - maxf <= k) ans = max(ans, r-l);
            else {
                map[s[l++]]--;
                for(auto &P : map) maxf = max(maxf, P.second);
            }

        }
        return ans;

    }
};