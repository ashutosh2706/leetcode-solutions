class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        for(int i=0; i<bits.size(); i++) {
            bits[i] = __builtin_popcount(i);
        }
        return bits;
    }
};