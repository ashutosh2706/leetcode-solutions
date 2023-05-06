class Solution {
public:
    string removeDuplicateLetters(string s) {

    vector<int> count(256, 0);
    vector<int> vis(256, 0);
    for(auto &c : s) count[c]++;
    string res = "0";

    for(auto &c : s) {
        count[c]--;
        if(vis[c]) continue;
        while(c < res.back() and count[res.back()]) {
            vis[res.back()] = 0;
            res.pop_back();
        }
        res += c;
        vis[c] = 1;
    }
    return res.substr(1);
    }
};