class Solution {
private:
    void f(int i, int n, int k, vector<int> v, vector<vector<int>> &res) {
    if(k==0) {
        res.push_back(v);
        return;
    }

    for(int x = i; x <= n; x++) {
        v.push_back(x);
        f(x+1, n, k-1, v, res);
        v.pop_back();
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> vec;
        f(1,n,k,v,vec);
        return vec;
    }
};