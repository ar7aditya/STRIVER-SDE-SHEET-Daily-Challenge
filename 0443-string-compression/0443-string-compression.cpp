class Solution {
public:
    int compress(vector<char>& chars) {
       string s="";
        int i = 0 ;
        while(i<chars.size()){
            int len=0;
            char char_to_check = chars[i];
            while(i<chars.size() && char_to_check == chars[i]){
                i++;
                len++;
            }
            s.push_back(char_to_check);
            if(len>1) s+=to_string(len);
        }
        // cout<<s<<endl;
        i=0;
        for(i=0;i<s.size();i++){
            chars[i]=s[i];
        }
        return s.size();
    }
};