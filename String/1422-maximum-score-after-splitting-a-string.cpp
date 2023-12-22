class Solution {
public:
    int maxScore(string s) {
        vector<int> left, right;
        int cnt = 0;
        for (auto& c : s) {
            if (c == '0')
                ++cnt;
            left.push_back(cnt);
        }

        cnt = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '1')
                ++cnt;
            right.push_back(cnt);
        }
        reverse(begin(right), end(right));
        int ans = 0;
        for (int i = 0; i < left.size() - 1; ++i) {
            ans = max(ans, left[i] + right[i + 1]);
        }
        return ans;
    }
};