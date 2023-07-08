class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& from, vector<int>& to) {
        set<int> st(begin(nums),end(nums));
        for(int i=0; i<from.size(); i++) {
            if(st.count(from[i])) {
                st.erase(from[i]);
                st.insert(to[i]);
            }
        }
        return vector<int>(begin(st),end(st));
    }
};