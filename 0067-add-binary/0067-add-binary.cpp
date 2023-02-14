class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.size();
        int m = b.size();
        if(abs(n-m)>0){
            int xtra = abs(n-m);
            string k="";
            while(xtra--){
                k.push_back('0');
            }
            if(n>m){
               k+=b;
               b=k; 
            }
            else {
                k+=a;
                a=k;
            }
        }
        int i=a.size()-1;
        int j=i;
        int carry=0;
        while(i>=0){
            if(a[i]=='1' && b[i]=='1'){
                if(carry==1){
                    ans.push_back('1');
                }
                else  {
                    ans.push_back('0');
                    carry=1;
                }
            }
            else if((a[i]=='0' && b[i]=='1') || (a[i]=='1' && b[i]=='0')){
                if(carry==1){
                    ans.push_back('0');
                }
                else ans.push_back('1');
            }
            else {
                if(carry==1){
                    ans.push_back('1');
                    carry=0;
                }
                else ans.push_back('0');
            }
            i--;
            j--;
        }
        if(carry==1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};