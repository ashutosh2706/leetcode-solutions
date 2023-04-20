class Solution {
private:
    long long dp[101][101];

    int get(int x,int y, int rx, int ry) {
    if(x==rx && y==ry) {
        return 1;
    }
    if(x+1<=rx) {
        if(dp[x+1][y]==0) {
            int xx = get(x+1,y,rx,ry);
            dp[x][y]+=xx;
        }
        else dp[x][y]+=dp[x+1][y];
    }

    if(y+1<=ry) {
        if(dp[x][y+1]==0) {
            int xx = get(x,y+1,rx,ry);
            dp[x][y]+=xx;
        }
        else dp[x][y]+=dp[x][y+1];
    }

    return dp[x][y];
}
    
public:
    int uniquePaths(int m, int n) {
        memset(dp,0,sizeof(dp));
        int res=get(0,0,m-1,n-1);
        return res;
    }
};