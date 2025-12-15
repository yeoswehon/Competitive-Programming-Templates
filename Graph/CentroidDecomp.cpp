// Remember to build!!! cen.build(0)
// Build: O(N log N), Paint/Query O(Log N), Memory O(N Log N)
// IMPT: Only add the edge once!!
template<typename T>
struct CentroidDecomp{
    int n; T INF;
    vector<vector<pair<int,T>>> adj;
    vector<int> level;
    vector<int> sub,par; // par: parent of centroid c
    vector<char> removed; // removed[x]: flag for this node already became a centroid
    vector<vector<pair<int,T>>> anc; // anc[v]: (centroid, dist(v,centroid))
    vector<T> best;                 // best[c]: min dist(c, any red)

    CentroidDecomp(int N=0,T inf=numeric_limits<T>::max()/4){init(N,inf);}
    void init(int N,T inf=numeric_limits<T>::max()/4){
        n=N; INF=inf; adj.assign(n,{});
        sub.assign(n,0); par.assign(n,-1); removed.assign(n,0);
        anc.assign(n,{}); best.assign(n,INF); level.assign(n,0);
    }
    void addEdge(int u,int v,T w=(T)1){adj[u].push_back({v,w}); adj[v].push_back({u,w});}

    int getsz(int u,int p){
        sub[u]=1;
        for(auto [v,w]:adj[u]) if(v!=p && !removed[v]) sub[u]+=getsz(v,u);
        return sub[u];
    }
    int getcen(int u,int p,int tot){
        for(auto [v,w]:adj[u]) if(v!=p && !removed[v] && sub[v]>tot/2) return getcen(v,u,tot);
        return u;
    }
    void adddist(int u,int p,int c,T d){
        anc[u].push_back({c,d});
        for(auto [v,w]:adj[u]) if(v!=p && !removed[v]) adddist(v,u,c,d+w);
    }
    void build(int entry=0,int p=-1,int lvl=0){
        int tot=getsz(entry,-1), c=getcen(entry,-1,tot);
        par[c]=p; removed[c]=1; anc[c].push_back({c,(T)0});
        level[c]=lvl;
        for(auto [v,w]:adj[c]) if(!removed[v]) adddist(v,c,c,w);
        for(auto [v,w]:adj[c]) if(!removed[v]) build(v,c,lvl+1);
    }
    void paint(int v){for(auto [c,d]:anc[v]) best[c]=min(best[c],d);} // paint node red monotonically
    T query(int v)const{ // query(v) returns the shortest distance from node v to any red (painted) node
        T ans=INF;
        for(auto [c,d]:anc[v]) if(best[c]<INF) ans=min(ans,best[c]+d);
        return ans;
    }
};
