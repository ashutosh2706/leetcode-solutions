class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<int> ind;
        int prev;
        for(int i=0; i<groups.size(); ++i) {
            if(i == 0) {
                prev = groups[i];
                ind.push_back(i);
                continue;
            }
            if(groups[i] != prev) {
                prev = groups[i];
                ind.push_back(i);
            }
        }

        vector<string> res;
        for(auto &u : ind) {
            res.push_back(words[u]);
        }
        return res;
        
    }
};