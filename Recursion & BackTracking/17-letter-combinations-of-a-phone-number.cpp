class Solution {
private:
vector<string> res;

void add(int i, vector<string> &v, string s) {
    if(s.length() == v.size()) {
        res.push_back(s);
        return;
    }
    if(i == v.size()) return;

    for(int x = 0; x < v[i].length(); x++) {
        s.push_back(v[i][x]);
        add(i+1, v, s);
        s.pop_back();
    }

}

public:
    vector<string> letterCombinations(string dig) {
    
    if(dig.length() == 0) return {};
    
    vector<string> v;
    map<int, string> mp;
    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";

    for(char &c:dig) {
        v.push_back(mp[c-'0']);
    }
    add(0, v, "");
    return res;

    }
};