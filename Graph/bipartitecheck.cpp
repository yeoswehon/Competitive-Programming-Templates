// 0-based indexing
template <typename T>
bool bipartite(int n,vector<vector<T>> &adj,vi &color) {
    color.assign(n, -1);
    queue<int> q;
    for(int s=0;s<n;s++){
        if (color[s]!=-1) continue;
        color[s]=0;
        q.push(s);
        while(!q.empty()){
            auto u =q.front();
            q.pop();
            for(T &v:adj[u]){
                if (color[v]==-1){
                    color[v]=color[u]^1;
                    q.push(v);
                } else if (color[v] == color[u]){
                    return false;
                }
            }
        }
    }
    return true;
}
