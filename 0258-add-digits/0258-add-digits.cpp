class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        while(s.size()!=1){
            int x = 0;
            for(char i : s){
                int m = i - '0';
                x+=m;
            }
            s = to_string(x);
        }
        return stoi(s);
    }
};