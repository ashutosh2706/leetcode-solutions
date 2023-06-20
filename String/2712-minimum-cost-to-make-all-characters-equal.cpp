class Solution {
public:
    long long minimumCost(string s) {
        
        auto flip = [](char& c) { return c=='0' ? '1' : '0'; };
        int N = s.length(), flips = 0;
        long long ans = 0;
        
        for(int i=0; i<N-1; i++) {
            char c1 = s[i], c2 = s[i+1];
            if(flips % 2 == 1) {
                c1 = flip(c1);
                c2 = flip(c2);
            }
            if(c1 != c2) {
                if((N-i-1) < (i+1)) {
                    flips++;
                    ans += (N-i-1);
                } else 
                    ans += (i+1);
            }
        }
        return ans;
    }
};

