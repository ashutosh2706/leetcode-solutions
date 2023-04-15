class Solution {
public:
    int arr[1001][2001];

    int func(int ind, vector<vector<int>>& piles, int k) {

        if(k == 0 || ind == piles.size()) return 0;
        int sum = 0, ans = 0;
        if(arr[ind][k] != -1) return arr[ind][k];
        for(int j=0; j<min(k, (int)piles[ind].size()); j++) {
            sum += piles[ind][j];
            ans = max(ans, sum + func(ind+1, piles, k-(j+1)));
        }
        return arr[ind][k] = max(ans, func(ind+1, piles, k));

    }  

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(arr, -1, sizeof(arr));
        return func(0, piles, k);
    }
};