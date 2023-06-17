class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left == right || left == 0) return left;
        // for(int i=0;i<31;i++){
        //     if((1 << i) >= left && (1 << i + 1) <= right) return 0;
        // }
        int c = 0;
        while( left != right){
            left = left>>1;
            right = right>>1;
            c++;
        }
        left = left<<c;
        return left;
    }
};