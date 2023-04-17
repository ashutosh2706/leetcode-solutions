class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int max = *max_element(begin(candies), end(candies));

        vector<bool> v(candies.size(), false);
        for(int i=0; i<candies.size(); i++) {
            if(candies[i] + extra >= max) v[i] = true;
        }

        return v;
    }
};