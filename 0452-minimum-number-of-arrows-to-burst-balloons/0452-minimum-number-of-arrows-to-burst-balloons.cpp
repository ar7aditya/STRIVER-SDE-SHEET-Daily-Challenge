bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
class Solution {
public:  
    int findMinArrowShots(vector<vector<int>>& segments) {
       sort(segments.begin(),segments.end(),cmp);
        int ans=1;
        int bound=segments[0][1];
        for(int i=1;i<segments.size();i++){
            if(segments[i][0]>bound){
                ans++;
                bound=segments[i][1];
            }
        }
        return ans;
    }
};