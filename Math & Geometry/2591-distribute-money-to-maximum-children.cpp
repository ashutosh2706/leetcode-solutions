class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children) return -1;
        money -= children;
        int Q = money/7, R = money%7;
        if(Q > children or (Q == children and R)) return children-1;
        else if(Q == children and R == 0) return children;
        else if(Q == children - 1 and R == 3) return children-2;
        else if(Q < children) return Q;
        return 0;
    }
};