class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        
        for(int i=0; i<num.length(); i++) {
            int x = num[i] - '0';
            if(change[x] > x) {
                while(i < num.length() and change[num[i] - '0'] >= (num[i] - '0')) {
                    num[i] = change[num[i]-'0'] + '0';
                    i++;
                }
                break;
            }
        }
        return num;
    }
};