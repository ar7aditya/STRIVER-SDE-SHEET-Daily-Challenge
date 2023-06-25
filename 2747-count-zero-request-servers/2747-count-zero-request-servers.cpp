class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        if(b[1] >= a[1]) return true;
        return false;
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q) {
        vector<int> ans(q.size());
        sort(logs.begin(),logs.end(),comp); // server_id , req_time
        
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq; // time id
        for(int i=0;i<q.size();i++) pq.push({q[i],i});
        
        unordered_map<int,int> mp; // server_id ,  no_of_server
        
        int left = 0 , right = 0;
        while(!pq.empty()){
            int start_time = max(0, pq.top().first - x);
            int end_time = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            while(right < logs.size() && logs[right][1] <= end_time) {
                int server_id = logs[right][0];
                mp[server_id]++;
                right++;
            }
            while(left < logs.size() && logs[left][1] < start_time){
                int server_id = logs[left][0];
                mp[server_id]--;
                if(mp[server_id] == 0) mp.erase(server_id);
                left++;
            }
            ans[index] = n - mp.size();
        }
        return ans;
    }
};