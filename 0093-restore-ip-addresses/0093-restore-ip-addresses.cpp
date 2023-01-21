class Solution {
public:
    void f(int start,int partition,string s,vector<string>& res,string temp){
        if(start==s.size() && partition==4){
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        if(s.size()-start>(4-partition)*3) return;
        if(s.size()-start<(4-partition)) return;
        int num=0;
        for(int i=start;i<start+3;i++){
            num=num*10 +(int)(s[i]-'0');
            if(num<=255){
                temp+=s[i];
                f(i+1,partition+1,s,res,temp+'.');
            }
            if(num==0) break;
        }
        return ;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        f(0,0,s,res,"");//start_index  partion_count given_string result_vector temp_string
        return res;
    }
};