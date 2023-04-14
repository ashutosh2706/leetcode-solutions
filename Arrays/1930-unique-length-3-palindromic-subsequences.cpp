// Time: O(26 * n)
// Space: O(n)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
    vector<pair<int, int>> vp(26, {-1, -1});
    int n = s.length();     // n ~ 1e5, so it's wise to calculate the length once

    for(int i=0; i<n; i++) {
        if(vp[s[i] - 'a'].first == -1) vp[s[i] - 'a'].first = i;
        else vp[s[i] - 'a'].second = i;         // store the last occurrence
    }

    int ans = 0;

    for(int i=0; i<26; i++) {
        if(vp[i].second != -1) {

            set<char> st;
            for(int x = vp[i].first + 1; x < vp[i].second; x++) st.insert(s[x]);
            ans += (int)st.size();

        }
    }
    return ans;
    }
};