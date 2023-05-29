class Solution {
private:
bool found(string &s1, string &s2) {
    int cnt = 0, n = s1.length();
    for(int i=0; i<n and cnt <= 2; i++) {
        cnt += !(s1[i] == s2[i]);
    }
    return cnt <= 2;
}
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
    vector<string> res;
    for(auto &s1:queries) {
        for(auto &s2:dict)
            if(found(s1,s2)) {
                res.push_back(s1);
                break;
            }
    }
    return res;
    }
};