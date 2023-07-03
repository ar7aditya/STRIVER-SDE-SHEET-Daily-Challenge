class Solution {
public:
    int minFlips(int a, int b, int c) {
        int a_or_b = a | b;
        int c_xor_res = a_or_b ^ c;
        int a_and_b = a & b;
        a_and_b = a_and_b & c_xor_res;
        int flip_bits = 0;
        while(c_xor_res != 0){
            int rsbm = c_xor_res & -c_xor_res;
            c_xor_res -= rsbm;
            flip_bits++;
        }
        while(a_and_b != 0){
            int rsbm = (a_and_b & -a_and_b);
            a_and_b -= rsbm;
            flip_bits++;
        }
        return flip_bits;
   }
};