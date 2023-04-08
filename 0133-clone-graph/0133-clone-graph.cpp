class Solution {
public:
    unordered_map<Node* , Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)  return NULL;
          if(node->neighbors.size()==0) return new Node(1);
        
      queue<Node*> q;
        Node* ans=new Node(node->val);
        mp[node]=ans;
        q.push(node);
        while(!q.empty()){
            Node* cur=q.front();q.pop();
            for(auto i: cur->neighbors){
                if(mp.find(i)==mp.end()){
                    mp[i]=new Node(i->val);
                    q.push(i);
                }
                mp[cur]->neighbors.push_back(mp[i]);
            }
        }
      return mp[node];
    }
};