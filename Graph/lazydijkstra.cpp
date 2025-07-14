vl dist(n,INF);
ll s=0;
dist[s]=0;
priority_queue<pll,vector<pll>,greater<pll>>pq;
pq.emplace(0,s);
while (!pq.empty()){
    auto [d,u]=pq.top();
    pq.pop();
    if (d>dist[u]) continue;
    for (auto &[v,w]:adj[u]){
        if (dist[u]+w>=dist[v]) continue;
        dist[v]=dist[u]+w;
        pq.emplace(dist[v],v);
    }
}
