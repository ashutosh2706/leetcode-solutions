class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        vector<vector<string>> v;
        for(int i=0; i<words.size(); ++i) {
            string e,o;
            for(int j=0; j<words[i].size(); ++j) {
                if(j&1) o+=words[i][j];
                else e+=words[i][j]; 
            }
            sort(begin(o),end(o));
            sort(begin(e),end(e));
            v.push_back({o,e});
        }
        sort(begin(v), end(v));
        int cnt = 0;
        for(int i=1; i<v.size(); ++i) {
            if(v[i][1] == v[i-1][1] and v[i][0] == v[i-1][0]) continue;
            cnt++;
        }
        return cnt+1;
    }
};