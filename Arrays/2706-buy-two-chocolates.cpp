class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices), end(prices));
        return money-(prices[0]+prices[1]) < 0 ? money : money-(prices[0]+prices[1]);
    }
};