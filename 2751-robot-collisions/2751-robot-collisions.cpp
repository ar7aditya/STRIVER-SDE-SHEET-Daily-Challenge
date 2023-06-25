class Solution {
public:
    class node{
        public:
            int pos;
            int heal;
            int id;
            char dir;
    };
    static bool comp(node* a,node* b){
        if(b->pos < a->pos) return false;
        return true;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ans(n);
        vector<node*> pq;
        for(int i=0;i<n;i++){
            node* n1 = new node();
            n1->pos = positions[i];
            n1->heal = healths[i];
            n1->id = i;
            n1->dir = directions[i];
            pq.push_back(n1);
        }
        sort(pq.begin(),pq.end(),comp);
        
        stack<node*> st;
        for(int i=0;i<n;i++){
            node* cur = pq[i];
            int pos = cur->pos;
            int heal = cur->heal;
            int id = cur->id;
            char dir = cur->dir;
            // cout<<pos<<" "<<heal<<" "<<id<<" "<<dir<<endl;
            if(dir == 'L') {
                if(st.empty()) ans[id] = heal;
                else{
                    while(!st.empty() && st.top()->heal < heal){
                        st.pop();
                        heal--;
                    }
                    if(st.empty()){
                        ans[id] = heal;
                    }
                    else if(st.top()->heal == heal) st.pop();
                    else{
                        st.top()->heal--;
                    }
                }
            }
            if(dir == 'R'){
                st.push(cur);
            } 
        }
        while(!st.empty()){
            int h = st.top()->heal;
            int id = st.top()->id;
            st.pop();
            ans[id] = h;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(ans[i] != 0) res.push_back(ans[i]);
        }
        return res;
    }
};