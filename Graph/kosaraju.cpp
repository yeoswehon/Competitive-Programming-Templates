// Time Complexity: O(N + M)
int N, M;
vvi g,gt;
vector<bool>vis;
vi ord;

void dfs1(int v){
    vis[v]=1;
    for(int &u:g[v]) if (!vis[u]) dfs1(u);
    ord.push_back(v);
}

void dfs2(int v){
    vis[v]=1;
    for(int &u:gt[v]) if (!vis[u]) dfs2(u);
}

int kosaraju(){ // no of SCCs
    vis.assign(N,0);
    for(int i=0;i<N;i++) if (!vis[i]) dfs1(i);
    vis.assign(N,0);
    int cnt=0;
    for (int i=N-1;i>=0;i--){
        if (!vis[ord[i]]){
            dfs2(ord[i]);
            cnt++;
        }
    }
    return cnt;
}

// In the main() function, remember!!
g.assign(N,{});
gt.assign(N,{});
