class Solution {
private:
int DP[201][201];
int f(int i, int j, vector<vector<int>>& t) {
    if(i == t.size() || j == t[i].size()) return 0;
    if(DP[i][j]!=-1) return DP[i][j];
    return DP[i][j] = min(t[i][j] + f(i+1,j,t), t[i][j]+f(i+1,j+1,t));
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(DP,-1,sizeof(DP));
        return f(0,0,triangle);
    }
};