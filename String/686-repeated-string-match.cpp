class Solution {
public:
    int repeatedStringMatch(string a, string b) {
    int l = 0, r = (b.length()/a.length())+2, mid;
    while(l < r) {
        mid = l + (r-l)/2;
        string tmp;
        for(int i=0; i<mid; ++i) {
            tmp += a;
        }
        if(tmp.find(b) != string::npos) {
            r = mid;
        } else l = mid+1;

    }

    string tmp;
    for(int i=0; i<l; ++i) tmp += a;
    if(tmp.find(b) != string::npos) return l;
    return -1;
    }
};