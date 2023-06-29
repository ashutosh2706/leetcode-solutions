class Solution {
public:
    int getMinSwaps(string num, int k) {
        string perm = num;
        while(k--) next_permutation(begin(perm), end(perm));
        int cnt = 0;
        for(int i=0; i<num.length(); i++) {
            if(num[i] == perm[i]) continue;
            int ind = i;
            while(ind < num.length() and perm[ind] != num[i]) ind++;
            while(ind != i) {
                swap(perm[ind], perm[ind-1]);
                cnt++;
                ind--;
            }
        }
        return cnt;
    }
};