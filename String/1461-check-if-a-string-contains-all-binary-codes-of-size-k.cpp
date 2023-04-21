class Solution {
public:
    bool hasAllCodes(string s, int k) {
    
    unordered_set<string> set;
    int n = s.length();
    for(int i=0; i<n; i++) {
        string ss = s.substr(i, k);
        if(ss.length() == k)
        set.insert(ss);
    }    

    int r = pow(2,k);
    int y = (int)set.size();
    return r == y;
    }
};