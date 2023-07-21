class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while(b != 0) {
            c = (a&b);    // generate carry
            a = a ^ b; // a = a^b;
            b = (unsigned int)(c)<<1;   // left shift carry by one bit so thaty it will be added with next bit sum

            // these a and b will be xored in next iteration and stored in a. there carry will be stored in c. when carry becomes 0, then a^b will give the correct answer and left shift of carry 0 will be 0, so loop breaks;
        }
        return a;
    }
};