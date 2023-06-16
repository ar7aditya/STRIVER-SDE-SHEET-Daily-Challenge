class Solution {
public:
    int minFlips(int a, int b, int c) {
        int AorB = (a | b);
        int AandB = (a & b);
        int x = (AorB ^ c );
        AandB = AandB & x;
        int bits_to_be_flipped = 0;
        while(x != 0){
            int rsbm = (x & -x);
            x = x - rsbm;
            bits_to_be_flipped++;
        }
        if(bits_to_be_flipped == 0) return 0;
        while(AandB != 0){
            int rsbm = (AandB & -AandB);
            AandB = AandB - rsbm;
            bits_to_be_flipped++;
        }
        return bits_to_be_flipped;
    }
};