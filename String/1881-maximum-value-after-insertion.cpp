class Solution {
public:
    string maxValue(string n, int x) {
        string res;
        bool b = 0;
        if(n[0] == '-') {
            res += '-';
            for(int i=1; i<n.length(); ++i) {
                if((n[i] - '0') > x) {
                    res += (char)('0' + x);
                    res += n.substr(i);
                    b = 1;
                    break;
                } else res += n[i];
            }

            if(!b) res += (char)('0'+x);

        } else {

            for(int i=0; i<n.length(); ++i) {
                if((n[i]-'0') < x) {
                    res += (char)('0'+x);
                    res += n.substr(i);
                    b = 1;
                    break;
                } else res += n[i];
            }
            if(!b) res += (char)('0'+x);
        }

        return res;

    }
};

