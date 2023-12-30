class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> f(26);
        for(auto &w : words) {
            for(auto &c : w) f[c-'a']++;
        }
        for(auto &a : f) {
            if(a % n) return 0;
        }
        return 1;
    }
};