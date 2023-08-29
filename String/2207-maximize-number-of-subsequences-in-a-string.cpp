class Solution {
public:
    long long count(string &res, string &pattern) {
        long long ans = 0, cnt = 0;
        for(int i=res.length()-1; i>=0; --i) {
            if(res[i] == pattern[0]) ans += cnt;
            if(res[i] == pattern[1]) cnt++;
        }
        return ans;
    }
    long long maximumSubsequenceCount(string &text, string &pattern) {
        string res;
        for(auto &c : text) {
            if(c == pattern[0] or c == pattern[1]) {
                res += c;
            }
        }

        res.push_back(pattern[1]);
        long long ans = count(res, pattern);
        res.pop_back();
        string tmp;
        tmp += pattern[0];
        tmp += res;
        ans = max(ans, count(tmp, pattern));
        return ans;
    }
};