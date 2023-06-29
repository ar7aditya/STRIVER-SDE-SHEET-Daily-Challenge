class Solution{ 
public:

    vector<vector<int> > fourSum(vector<int> &num, int target){
        vector<vector<int> > vvi;
        long long n = num.size();
        if(n < 4) return  vvi;
        
        sort(num.begin(), num.end());        
        unordered_map<long long, vector<pair<long long, long long>> > mp;
        for(long long i = 0; i < n; i++){
            for(long long j = i + 1; j < n; j++){
                mp[num[i]+num[j]].push_back(make_pair(i,j));
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i>0 && num[i] == num[i-1]) continue;
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && num[j] == num[j-1]) continue;
                long long res = (long long)target - (long long)num[i] - (long long)num[j];
                if(mp.count(res)){
                    for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                        long long k = (*it).first, l = (*it).second;
                        if(k > j){ 
                            if(!vvi.empty() && num[i]==vvi.back()[0] && num[j]==vvi.back()[1]
                            && num[k]==vvi.back()[2] && num[l] == vvi.back()[3]){
                                continue; 
                            }
                            vector<int> vi={num[i], num[j], num[k], num[l]};
                            vvi.push_back(vi);
                        } 
                        
                    }
                }
            }
        }
        return vvi;
    }
  };