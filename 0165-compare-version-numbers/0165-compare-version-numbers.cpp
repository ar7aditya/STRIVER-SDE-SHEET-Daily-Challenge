class Solution {
public:
    int check(string a,string b){
        if(a.size()==0) return 0;
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i]) return 1;
            if(a[i]<b[i]) return -1; 
        }
        return 0;
    }
    
    int compareVersion(string v1, string v2) {
        int n=v1.size();
        int m=v2.size();
        int i=0,j=0;
        string num1,num2;
        while(i<n && j<m){
            num1="",num2="";
            while(v1[i]=='0')i++;
            while(v2[j]=='0')j++;
            
            while(i<n && v1[i]!='.'){
                num1=num1+v1[i];
                i++;
            }
            while(j<m && v2[j]!='.'){
                num2=num2+v2[j];
                j++;
            }
            if(num1.size()>num2.size()) return 1;
            else if(num1.size()<num2.size()) return -1;
            else{
            if(check(num1,num2)==1) return 1;
            else if(check(num1,num2)==-1) return -1;
            else{i++;j++;}
            }
        }
        while(i<n) {
            if(v1[i]!='.' && v1[i]!='0') return 1;
            i++;
        }
        while(j<m) {
            if(v2[j]=='.' || v2[j]=='0') j++;
            else return -1;
        }
        return 0;
    }
};