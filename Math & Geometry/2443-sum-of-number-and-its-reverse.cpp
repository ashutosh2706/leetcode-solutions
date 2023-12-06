class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i=num; i>=0; --i) {
            string a = to_string(i);
            string b = to_string(num-i);
            while(a.size() > 1 and a.back() == '0') a.pop_back();
            std::reverse(begin(a), end(a));
            if(a == b) return 1;
        }
        return 0;
    }
};
