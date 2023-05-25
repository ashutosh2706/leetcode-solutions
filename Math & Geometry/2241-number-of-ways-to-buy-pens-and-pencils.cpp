class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        int p1 = 0;
        long long ways = 0;
        while(p1*cost1 <= total) {
            int rem = total - (p1*cost1);
            ways += floor(rem/cost2)+1;
            p1++;
        }
        return ways;
    }
};