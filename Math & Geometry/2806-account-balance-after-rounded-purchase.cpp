class Solution {
public:
    int accountBalanceAfterPurchase(int amt) {
        if(amt == 0) return 100;
        int x = amt % 10;
        if(x >= 5) {
            amt += (10 - x);
        }else {
            amt -= x;
        }
        return 100 - amt;
        
    }
};