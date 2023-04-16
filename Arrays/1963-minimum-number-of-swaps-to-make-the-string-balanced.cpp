class Solution {
public:
    int minSwaps(string s) {

    int u = 0, d = 0;
    for(char &c:s) {
        if(c == '[') u++;
        else {
            if(u > 0) u--;
            else d++;
        }
    }
    return ceil((float)d/2);

    }
};