class Solution {
private:
bool check(map<char, int> &m1, map<char,int> &m2) {
    int f=1;
    for(auto it:m1) {
        if(m2[it.first] != it.second) { f=0; break; }
    }
    return f==1;
}
public:
    bool checkInclusion(string s1, string s2) {
    int n1 = s1.length(), n2 = s2.length();
    if(n1 > n2) return false;
    map<char, int> m1,m2;
    for(int i=0; i<n1; i++) m1[s1[i]]++;
    int s=0, e=-1;
    while(e < n2) {
        m2[s2[++e]]++;
        if(e-s+1 == n1) {
            if(check(m1,m2)) return true;
            else m2[s2[s++]]--;
        }
    }
    return false;
    }
};