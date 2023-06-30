class Solution {
public:
    bool compare(string &s1, string &s2) {
        if(s1 == s2) return 1;
        int p1=0, p2 = 0;
        while(p1 < s1.length() and p2 < s2.length()) {
            if(s1[p1] == s2[p2]) {
                p1++;
                p2++;
            } else p2++;
        }
        return p1 == s1.length();
    }
    
    int findLUSlength(vector<string>& strs) {
        
        int ans = -1;
        for(int i=0; i<strs.size(); i++) {
            bool b = 1;
            for(int j=0; b and j<strs.size(); j++) {
                if(i == j) continue;
                if(compare(strs[i], strs[j])) 
                    b = 0;
            }
            if(b) ans = max(ans, (int)strs[i].length());
        }
        return ans;
    }
};