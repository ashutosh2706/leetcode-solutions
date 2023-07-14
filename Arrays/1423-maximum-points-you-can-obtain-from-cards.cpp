class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int N = cards.size(), ans = 1e9, sum = 0;
        for(int l = 0, r=0; r < N; r++) {
            sum += cards[r];
            if(r-l +1 > (N-k)) {
                sum -= cards[l++];
            }
            if(r-l+1 == (N-k)) ans = min(ans, sum);
        }
        return (accumulate(begin(cards),end(cards), 0) - ans);
    }
};