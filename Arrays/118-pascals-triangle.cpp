class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    int n=numRows;
    vector<vector<int>> v;
    v.push_back(vector<int> {1});
    if(n==1) return v;
    v.push_back(vector<int> {1,1});
    if(n==2) return v;
    n-=2;
    while(n--) {
        vector<int> tmp = v.back(),nv;
        nv.push_back(1);
        for(int i=0;i<tmp.size()-1;i++)
        {
            nv.push_back(tmp[i]+tmp[i+1]);
        }
        nv.push_back(1);
        v.push_back(nv);
    }
    return v;
    }
};