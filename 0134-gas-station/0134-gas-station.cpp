class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> p(n);
        priority_queue<pair<int,int>> pq;
        long long int s=0;
        for(int i=0;i<n;i++){
            p[i]=gas[i]-cost[i];
            s+=p[i];
            if(p[i]>=0)pq.push({p[i],i});
        }
        if(s<0) return -1;
        while(!pq.empty()){
            int i=pq.top().second;
            pq.pop();
            if(p[i]<0) continue;
            int k=i;
            s=0;
            while(k-i<n){
               s+=p[k%n];
                k++;
               if(s<0) break;
            }
            if(s>=0 && k-i==n) return i;
        }
        return -1;
    }
};