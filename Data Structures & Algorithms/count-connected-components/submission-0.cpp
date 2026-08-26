class Solution {
public:
    void dfs(int src, vector<bool>& visited, unordered_map<int,vector<int> >& adj) {
        if(visited[src]) {
            return;
        }
        visited[src] = true;
        for(auto i: adj[src]) {
            dfs(i,visited,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int> > adj;
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i,visited,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
