class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(begin(piles), end(piles), greater<int>());
        int sum = 0, c = (int)piles.size()/3, cnt=0;
        for(int i=1; cnt < c; i+=2) {
            sum += piles[i];
            ++cnt;
        }
        return sum;
    }
};