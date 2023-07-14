class Solution {
public:
    vector<int> partitionLabels(string s) {
    vector<int> f(26);
    vector<int> res;
    for(auto &c:s) f[c-'a']++;
    unordered_set<char> set;
    int N = s.length(), ind = 0, l = 0;
    while(ind < N) {
        if(set.empty() or set.count(s[ind]) == 0) {
            set.insert(s[ind]);
        }
        if(--f[s[ind] - 'a'] == 0) {
            set.erase(s[ind]);
        }
        if(set.size() == 0) {
            res.push_back(ind-l+1);
            l = ind+1;
        }
        ind++;
    }
    return res;
    }
};