class Solution {
public:
    int totalMoney(int n) {
        int money = 0, prev = 0,curr, pm = 0;
        for(int i=0; i<n; ++i) {
            if(i == 0 or i%7 == 0) {
                curr = prev+1;
                prev = curr;
                money += curr;
                pm = curr;
            } else {
                money += ++pm;
            }
        }
        return money;
    }
};
