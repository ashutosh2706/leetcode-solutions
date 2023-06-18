class Solution {
public:
    int distanceTraveled(int M, int A) {
        int dist = 0;
        while(M > 0) {
            if(M >= 5) {
                M-=5;
                dist += 50;
                if(A) {
                    M++;
                    A--;
                }

            } else {
                dist += M*10;
                M = 0;
            }
        }
        return dist;
    }
};