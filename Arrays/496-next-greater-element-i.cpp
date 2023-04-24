class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {

    vector<int> t(n2.begin(), n2.end());
    unordered_map<int, int> m2;
    for(int i=0; i<n2.size(); i++) m2[n2[i]] = i;
    t.back() = -1;
    for(int i=n2.size() - 2; i>=0; i--) {
        int next = -1;
        for(int j = i+1; j < n2.size(); j++) {
            if(n2[j] > n2[i]) {
                next = n2[j];
                break;
            }
        }
        t[i] = next;
    }

    vector<int> res;
    for(auto &a:n1) res.push_back(t[m2[a]]);
    return res;      
    }
};