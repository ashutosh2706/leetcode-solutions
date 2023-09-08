class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> vec;
        for(int i=1; i<=m; i++) {
            vec.emplace_back(i);
        }
        vector<int> res;
        for(auto &q : queries) {
            int i=0;
            for(;i<vec.size(); i++) {
                if(vec[i] == q) {
                    res.emplace_back(i);
                    break;
                }
            }

            for(int x=i-1; x>=0; x--) {
                vec[x+1] = vec[x];
            }
            vec[0] = q;
        }
        return res;
    }
};