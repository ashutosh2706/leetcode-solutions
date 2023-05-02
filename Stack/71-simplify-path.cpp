class Solution {
public:
    string simplifyPath(string path) {
    vector<string> lev;
    string s = "";
    for(auto &c:path) {
        if(c == '/') {
            if(s.length() > 0) lev.push_back(s);
            s = "";
            continue;
        }
        s+=c;
    }
    if(s.length() > 0) lev.push_back(s);

    int ptr = 0;
    vector<string> vec;
    while(ptr < lev.size()) {
        
        if(lev[ptr] == ".." && vec.size() == 0 || lev[ptr] == ".") {
            ptr++;
            continue;
        }
        if(lev[ptr] == "..") vec.pop_back();
        else vec.push_back(lev[ptr]);
        ptr++; 
    } 
    
    string _path = "";
    for(auto &s:vec) 
        _path += "/" + s;

    return _path.length() == 0 ? "/" : _path;

    }
};