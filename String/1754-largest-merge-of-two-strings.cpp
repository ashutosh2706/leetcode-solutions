class Solution {
public:
    string largestMerge(string &w1, string &w2) {
        int i1=0, i2=0, n1=w1.length(), n2=w2.length();
        string res;
        while(i1 < n1 and i2 < n2) {
            if(w1[i1] < w2[i2]) res.push_back(w2[i2++]);
            else if(w2[i2] < w1[i1]) res.push_back(w1[i1++]);
            else {
                if(w1.substr(i1) > w2.substr(i2)) res += w1[i1++];
                else res += w2[i2++];
            }
        }
        while(i1 < n1) res += w1[i1++];
        while(i2 < n2) res += w2[i2++];
        
        return res;
    }
};