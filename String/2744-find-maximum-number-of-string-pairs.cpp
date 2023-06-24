class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int pairs = 0;
        for(int i=0; i<words.size()-1; i++) {
            string s = words[i];
            reverse(begin(s), end(s));
            for(int j=i+1; j<words.size(); j++) {
                if(words[j] == s) pairs++;
            }
        }
        return pairs;
    }
};