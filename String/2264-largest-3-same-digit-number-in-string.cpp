class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        int n = num.length();
        for(int i=0; i<num.length(); ++i) {
            string tmp = "";
            for(int j=i; j<n; ++j) {
                if(tmp.empty() or tmp.back() == num[j]) tmp += num[j];
                else {
                    tmp = "";
                    tmp += num[j];
                }
                if(tmp.length() == 3) {
                    if(ans.empty() or stoi(tmp) > stoi(ans)) ans = tmp;
                }
            }
        }
        return ans;
    }
};
