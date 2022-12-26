class Solution {
public:
    string f(int n,int k,vector<int> v,string& s,vector<int> fac){
        if(n==0) return s;
        int idx=k/fac[n-1];
        if(k%fac[n-1]==0) idx--;
        k -= fac[n-1] * idx;
        s+= to_string(v[idx]);
        v.erase(v.begin()+idx);
        f(n-1,k,v,s,fac);
        return s;
    }
    
    string getPermutation(int n, int k) {
        vector<int> factorial ={1,1,2,6,24,120,720,5040,40320,362880};
        string s="";
        vector<int> v;
        for(int i=1;i<=n;i++) v.emplace_back(i);
        return f(n,k,v,s,factorial);
    }
};