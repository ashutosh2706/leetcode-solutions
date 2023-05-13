class Solution {
const unsigned int mod = 1e9+7;
private:
int A[100001];
int dfs(int length, int &zero, int &one, int &lo, int &hi) {
    if(length == hi) return 1;
    if(length > hi) return 0;
    if(A[length] != -1) return A[length];
    int res = 0;
    if(length >= lo) res = 1;
    res = (res + dfs(length + zero, zero, one, lo, hi) % mod) % mod;
    res = (res + dfs(length + one, zero, one, lo, hi) % mod) % mod;
    return A[length] = (res % mod);
}
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(A,-1,sizeof(A));
        return dfs(0, zero, one, low, high);
    }
};