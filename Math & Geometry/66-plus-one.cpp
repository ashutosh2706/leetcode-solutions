class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back() < 9) {
            digits.back() += 1;
            return digits;
        }

        int carry = 1;
        for(int i=digits.size()-1; i>=0; i--) {
            if(digits[i] == 9) digits[i] = 0;
            else { 
                digits[i] += 1;
                return digits;
            }
        }

        vector<int> digit {1};
        for(int i=0; i<digits.size(); i++) digit.push_back(0);
        return digit;

    }
};