class Solution {
public:
    long long minimumSteps(string s) {
        vector<int> b,w;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '1') b.push_back(i);
            else w.push_back(i);
        }
        long long ans;
        long long ptr = 0, cnt = 0;
        for(auto &ind : w) {
            cnt += ind-ptr;
            ++ptr;
        }

        ans = cnt;
        cnt = 0, ptr = s.length()-1;
        for(auto &ind : b) {
            cnt += ptr-ind;
            --ptr;
        }
        return min(ans, cnt);
    }
};
