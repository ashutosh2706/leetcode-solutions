class Solution {
public:
    string sortVowels(string s) {
        set<char> vow {'A','E','I','O','U','a','e','i','o','u'};
    string ss;
    map<int,char> map;
    for(int i=0; i<s.length(); i++) {
        if(vow.count(s[i])) {
            ss += s[i];
        }else map[i] = s[i];
    }

    sort(ss.begin(), ss.end(), [](char &c1, char &c2){
        return ((int)c1 < (int)c2);
    });

    string res;
    int l = 0;
    for(int i=0; i<s.length(); i++) {
        if(map.count(i)) {
            res.push_back(map[i]);
        }else {
            if(l < ss.length()) {
                res.push_back(ss[l++]);
            }
        }
    }
        return res;
    }
};