class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        if(st.empty() || st.top().first>price){ st.push({price,1}); return ans;}
        else{
            while(!st.empty() && st.top().first<=price){
            ans+=st.top().second;
            st.pop();
            }
            st.push({price,ans});
        }   
        return ans;
    }
};