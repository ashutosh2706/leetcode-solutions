class Solution {
public:
    string smallestSubsequence(string s) {
    
        vector<int> vis(128, 0);
        map<char, int> map;
        for(auto &c : s) map[c]++;
        vector<char> stk;
        stk.push_back('0');
        for(auto &c : s) {
            map[c]--;
            if(vis[c]) continue;
            while(stk.back() > c and map[stk.back()]) {
                vis[stk.back()] = 0;
                stk.pop_back();
            }
            stk.push_back(c);
            vis[c] = 1;
        }
        return string(++begin(stk), end(stk));
    }
};