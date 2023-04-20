// Time: O(10*n)

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    
    if(s.length() < 10) return {};
    int n = s.length();
    map<string, int> map;
    for(int i=0; i<=n-10; i++) map[s.substr(i, 10)]++;

    vector<string> ans;
    for(auto &a:map) {
        if(a.second > 1) ans.push_back(a.first);
    }

    return ans;
        
    }
};