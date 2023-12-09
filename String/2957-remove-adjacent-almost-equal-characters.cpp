class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int cnt=0;
        
        auto eq = [](char &a, char &b) {
            if(a == b) return 1;
            if((char)(a+1) == b) return 1;
            if(a != 'z' and (char)(a-1) == b) return 1;
            return 0;
        };
        
        for(int i=1; i<word.length();) {
            if(eq(word[i], word[i-1]) or eq(word[i-1], word[i])) {
                ++cnt;
                i+=2;
            } else ++i;
        }
        return cnt;
    }
};