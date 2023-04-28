class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        set<char> st;
        int ans = 1, left = 0, right = 1;
        st.insert(s[left]);
        while(right < s.length()) {
            char c = s[right++];
            while(st.find(c) != st.end()) {
                st.erase(s[left++]);
            }
            st.insert(c);
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};