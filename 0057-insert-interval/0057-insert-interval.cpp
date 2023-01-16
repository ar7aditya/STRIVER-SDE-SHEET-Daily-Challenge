class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& G, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=G.size();
        int a=newInterval[0],b=newInterval[1];
        if(n==0 ) return {{a,b}};
        int first=INT_MAX,second=INT_MIN;
        if(a>G[n-1][1]) {G.push_back(newInterval);return G;}
        if(b< G[0][0]) {
            ans.push_back(newInterval);
            for(int i=0;i<n;i++) ans.push_back({G[i][0],G[i][1]});
            return ans;
        }
        int i=0;
        while(i<n){
            int start=G[i][0];
            int end=G[i][1];
            if(end<a) ans.push_back({start,end});
            else if(start>b) { ans.push_back({a,b});i--; break;}
            else {
            first=min(a,start);
             while(i<n-1 && G[i+1][0]<=b ) i++;
            second=max(G[i][1],b);
               ans.push_back({first,second});
                break;
            }
            i++;
        } 
        i++;
        while(i<n){
            int start=G[i][0];
            int end=G[i][1];
           ans.push_back({start,end});
            i++;
        }
        return ans;
    }
};