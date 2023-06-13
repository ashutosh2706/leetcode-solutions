class Solution {
public:
    string intToRoman(int i) {
        map<int, string> m;
        m[1]="I";
        m[2]="II";
        m[3]="III";
        m[4]="IV";
        m[5]="V";
        m[9]="IX";
        m[10]="X";
        m[40]="XL";
        m[50]="L";
        m[90]="XC";
        m[100]="C";
        m[400]="CD";
        m[500]="D";
        m[900]="CM";
        m[1000]="M";
        string res;
        while(i) {
            for(auto it = rbegin(m); it!=rend(m); it++) {
                if(it->first <= i) {
                    res += it->second;
                    i -= it->first;
                    break;
                }
            }
        }
        return res;
    }
};