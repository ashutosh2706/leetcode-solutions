class Solution {
public:
    vector<int> closestDivisors(int n) {
    int p = n+1, q = n+2;
    vector<int> r(2);
    int u1 = sqrt(p), u2 = sqrt(q), d = INT_MAX;
    for(int i=1; i<=u1; i++) {
        if(p % i == 0) {
            int x = p/i;
            if(d == INT_MAX or abs(i-x) < d) {
                r[0] = i;
                r[1] = x;
                d = abs(i-x);
            }
        }
    }

    for(int i=1; i<=u2; i++) {
        if(q % i == 0) {
            int x = q/i;
            if(d == INT_MAX or abs(i-x) < d) {
                r[0] = i;
                r[1] = x;
                d = abs(i-x);
            }
        }
    }
    return r;
    }
};