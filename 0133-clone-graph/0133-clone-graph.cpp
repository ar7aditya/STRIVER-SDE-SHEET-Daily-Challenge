class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        if(node == NULL) return NULL;
        if(node->neighbors.size() == 0) return new Node(node->val);
        unordered_map<Node*,Node*> mp;
        mp[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto i : cur->neighbors){
                if(mp.find(i) == mp.end()){
                    mp[i] = new Node(i->val);
                    q.push(i);
                }
                mp[cur]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];
    }
};