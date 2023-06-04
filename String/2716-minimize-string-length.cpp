class Solution {
public:
    int minimizedStringLength(string s) {
        set<int> set;
        int n = s.length();
        for(int i=0; i<n; i++) {
            if(set.count(i)) continue;
            int l = i-1, r = i+1;
            while(l >=0 ) {
                if(set.count(l) == 0 and s[l] == s[i]) set.insert(l);
                l--;
            }
            while(r < n) {
                if(set.count(r) == 0 and s[r] == s[i]) set.insert(r);
                r++;
            }
        }
        return n - (int)set.size();
    }
};