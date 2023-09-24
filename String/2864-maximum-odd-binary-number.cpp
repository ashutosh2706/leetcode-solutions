class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0, cnt0=0;
        for(auto &c:s) 
            if(c=='1') cnt1++;
        else cnt0++;
        
        string res;
        while((cnt1-1) > 0) {
            res+='1';
            cnt1--;
        }
        while(cnt0) {
            res += '0';
            cnt0--;
        }
        res += '1';
        return res;
        
    }
};