class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int last = 0, alt = 0;
        for(auto& i : gain) {
            last += i;
            alt = max(alt, last);
        }
        return alt;
    }
};