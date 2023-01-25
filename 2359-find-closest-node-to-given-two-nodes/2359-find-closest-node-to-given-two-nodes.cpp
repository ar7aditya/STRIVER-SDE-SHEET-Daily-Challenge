class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1==node2) return node1;
        int n=edges.size();
        vector<vector<int>> adj(n);
        vector<int> dis1(n,1e6);
        vector<int> dis2(n,1e6);
        int k=0;
        int i=0;
        int ind=node1;
        while(i<n){
            if(dis1[ind]!=1e6) break;
           dis1[ind]=k++;
           ind=edges[ind];
            if(ind==-1) break;
            i++;
        }
        i=0;
        k=0;
        ind=node2;
        while(i<n){
           if(dis2[ind]!=1e6) break;
           dis2[ind]=k++;
           ind=edges[ind];
            if(ind==-1) break;
            i++;
        }
        
        int ans=1e6;
        int index=-1;
        for(int i=0;i<n;i++){
            int s=max(dis1[i],dis2[i]);
            if(s<ans){
                ans=min(ans,s);
                index=i;
            }
        }
        return index;
    }
};