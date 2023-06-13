class Solution {
public:
    string f(int n,string& s){
       if(n == 1) return s;
        string temp = "";
        int count_unique = 1;
        int j = 1;
        for(j=1;j<s.size();j++){
            if(s[j] != s[j-1]){
                temp += to_string(count_unique);
                temp.push_back(s[j-1]);
                count_unique = 1;
            }
            else{
                count_unique++;
            }
        }
         if(j == s.size()){
                temp += to_string(count_unique);
                temp.push_back(s[j-1]);
            }
        // cout<<temp<<endl;
        return f(n-1,temp);;
    }
    
    string countAndSay(int n) {
        string j = "1";
        return f(n,j);
    }
};