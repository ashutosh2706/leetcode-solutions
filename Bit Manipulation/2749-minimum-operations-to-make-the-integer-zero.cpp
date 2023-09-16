/*
    n1 - (2^x + n2) - (2^x + n2) - (2^x + n2) ...k times = 0
=>  n1 - k*(2^x + n2) = 0
=>  n1 - k*2^x - k*n2 = 0
=>  n1 - k*n2 = k*2^x

    Now, lowest value possible of LHS expression k (for x=0 in RHS)
    and the largest value is k*2^60 (for x=60)
    So, 2 <= (n1 - k*n2) <= k*2^60

    Try every value of k from 1 to 60 in above inequation and check if it satisfies.
    To check whether (n1 - k*n2) <= k*2^x is possible for any particular k, use count of set bits
    If the set bit count in (n1 - k*n2) <= k, then eqn satisfies
*/

class Solution {
public:
    int makeTheIntegerZero(int n1, int n2) {

        for(int k=0; k<=60; k++) {
            long long x = (long long)n1 - (long long)(k*(long long)n2);
            if(k <= x and __builtin_popcountll(x) <= k)
                return k;
        }
        return -1;
    }
};