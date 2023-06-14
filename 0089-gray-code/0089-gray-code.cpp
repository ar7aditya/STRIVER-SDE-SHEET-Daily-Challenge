class Solution {
public:
    int b_to_d(string s){
        int num = 1;
        int ans = 0;
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            int x = s[i] - '0';
            ans += num * x;
            num = num * 2;
        }
        return ans;
    }
    vector<string> f(int n){
        if(n == 1){
            return {"0","1"};
        }
        vector<string> res = f(n-1);
        vector<string> new_res;
        for(int i=0;i<res.size();i++){
            new_res.push_back("0"+res[i]);
        }
        for(int i=res.size()-1;i>=0;i--){
            new_res.push_back("1"+res[i]);
        }
        return new_res;
    }
    vector<int> grayCode(int n) {
        vector<string> ans = f(n);
        vector<int> res;
        for(int i=0;i<ans.size();i++){
            int x = b_to_d(ans[i]);
            res.push_back(x);
        }
        return res;
    }
};