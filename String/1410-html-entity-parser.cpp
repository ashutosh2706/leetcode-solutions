class Solution {
public:
    string entityParser(string text) {
    unordered_map<string, char> map;
    map["&quot;"] = '\"';
    map["&apos;"] = '\'';
    map["&amp;"] = '&';
    map["&gt;"] = '>';
    map["&lt;"] = '<';
    map["&frasl;"] = '/';
    string res = "";
    int i = 0, n = text.length();
    while(i < n) {

        if(text[i] == '&') {
            string ss = "&";
            i++;
            while(i < n and text[i] != ';') {
                if(text[i] == '&') {
                    res += ss;
                    ss = "&";
                    i++;
                }
                ss += text[i++];
            }
            if(i < n) ss += text[i++];
            if(map.count(ss)) res += map[ss];
            else res += ss;
        }
        else res += text[i++];
    }
    return res;
    }
};