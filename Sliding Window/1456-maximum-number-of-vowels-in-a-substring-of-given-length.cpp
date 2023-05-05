class Solution {
public:
    int maxVowels(string s, int k) {

        auto isvow = [](char c) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
            return 0;
        };

        int ans = 0, l = 0, N = s.length(), vc = 0;
        for(int r=0; r < N; r++) {
            if(r - l + 1 > k)  {
                if(isvow(s[r])) vc++;
                if(isvow(s[l++])) vc--;
            } else if(isvow(s[r])) vc++;
            if(r - l + 1 == k)
            ans = max(ans, vc);
        }

        return ans;
    }
};