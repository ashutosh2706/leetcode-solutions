class Solution {
private:
    pair<int,int> search(string &num, char a, char b, char c) {
        int n = num.length();
        int x = 1e3, y = 1e3;
        for(int i=n-1; i>=0; --i) {
            if(num[i] == c) {
                y = i;
                break;
            }
        }
        if(y != 1e3) {
            for(int i=y-1; i>=0; --i) {
                if(num[i] == a or num[i] == b) {
                    x = i;
                    break;
                }
            }
        }
        return {x,y};
    }
    
public:
    int minimumOperations(string &num) {
        if(num == "0") return 0;
        int n = num.length();
        int ans = n;
        auto p1 = search(num, '2', '7', '5');
        int x = p1.first, y = p1.second;
        if(x != 1e3 and y != 1e3) {
            ans = min(ans, (n-y-1) + (y-x-1));
        }
        p1 = search(num, '0', '5', '0');
        x = p1.first, y = p1.second;
        if(x != 1e3 and y != 1e3) {
            ans = min(ans, (n-y-1) + (y-x-1));
        }
        if(y != 1e3) ans = min(ans, n-1);
        return ans;
    }
};