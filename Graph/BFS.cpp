// Computing unweighted shortest‐path distances from a source s in an adjacency-list graph
vi dist(n, -1);
dist[s]=0;
queue<int> q;
q.push(s);
while (!q.empty()){
  auto u=q.front();
  q.pop();
  for (auto &v:adj[u]){
    if (dist[v] != -1) continue;
    dist[v]=dist[u]+1;
    q.push(v);
  }
}
