vi res;
queue<ll>q;
for(int u=0;u<n;u++){
    if (!in[u]){
        q.push(u);
    }
}
while(!q.empty()){
    auto u=q.front();
    q.pop();
    res.eb(u);
    for(auto &v:adj[u]){
        in[v]--;
        if (in[v]) continue;
        q.push(v);
    }
}

if (res.sz!=n){ // cycle
  cout<<-1<<"\n;
    return;
}
