class Solution {
public:
    void bfs(unordered_map<int,vector<int>>& adj,vector<bool>& visited,
    vector<int>& parent, int src, bool& isCycle ) {
        if(visited[src]) {
            return;
        }

        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(auto i: adj[front]) {
                if(!visited[i]) {
                    parent[i] = front;
                    visited[i] = true;
                    q.push(i);
                } else {
                    if(parent[front] != i) {
                        isCycle = true;
                        return;
                    }
                }
            }
        }

        

    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        vector<int> parent(n);
        bool isCycle = false;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                bfs(adj,visited,parent,i,isCycle);
                cnt++;
            }
        }
        
        if(cnt > 1) {
            return false;
        }
        return !isCycle;
    }
};
