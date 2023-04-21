class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto &s : emails) {

            int i = 0;
            string mail = "";
            while(s[i] != '@') {
                if(s[i] == '.') { i++; continue; }
                if(s[i] == '+') { while(s[i] != '@') i++; }
                else mail+=s[i++];
            }
            mail += s.substr(i);
            st.insert(mail);
        }
        return (int)st.size();
    }
};