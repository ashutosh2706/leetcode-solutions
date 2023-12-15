class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(auto &p : paths) {
            st.insert(p[0]);
        }
        for(auto &p : paths) {
            if(st.count(p[1]) == 0) return p[1];
        }
        return "";
    }
};