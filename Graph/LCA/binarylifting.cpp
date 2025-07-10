#include <bits/stdc++.h> // https://cses.fi/alon/task/1688/
using namespace std;
using ll=long long;
using dd=long double;
using vi=vector<int>;
using vl=vector<long long>;
using vvi=vector<vector<int>>;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define read(a) for(auto&b:a) cin>>b;
#define FOR(i,n) for(ll i=0;(i)<(ll)(n);(i)++)
#define FOR2(i,n) for(ll i=(n)-1;i>=ll(0);i--)
#define SUM(a) accumulate((a).begin(),(a).end(),0LL)
#define SORT(a) sort(a.begin(),a.end())
#define RSORT(a) sort(a.rbegin(),a.rend())
#define UNIQUE(a) sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end()); // sorting included
#define VEC(a,n) vector<int> a(n);for(auto& b:a) cin>>b;
#define sz size()
#define all(x) x.begin(),x.end()
template<class T,class S>inline bool chmax(T&a,const S&b){return(a<b?a=b,1:0);}
template<class T,class S>inline bool chmin(T&a,const S&b){return(a>b?a=b,1:0);}

bool betelgeuse=0;
const ll MAX_N=3000000;
const ll MOD2=1000000007;
const ll INF=1e18;
const int LOG=20; // ideally ceil(log2(n))

int up[MAX_N+1][LOG], depth[MAX_N+1];
vi adj[MAX_N+1];

void dfs(int u,int p=0){
    up[u][0]=p;
    for(int i=1;i<LOG;i++){
        up[u][i]=up[up[u][i-1]][i-1];
    }
    for(auto &v:adj[u]){
        if (v==p) continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}

int lca(int a,int b){ // 0-based
    if (depth[a]<depth[b]) swap(a,b);
    int k=depth[a]-depth[b];
    for(int i=0;i<LOG;i++){
        if (k&(1LL<<i)){
            a=up[a][i];
        }
    }
    if (a==b) return a;
    for(int i=LOG-1;i>=0;i--){
        if (up[a][i]!=up[b][i]){
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}

void solve() {
    int n,q;
    cin>>n>>q;
    // memset(depth,0,sizeof(depth));
    // memset(up,0,sizeof(up));
    // FOR(i,n+1) adj[i].clear();
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        adj[i].eb(--x);
        adj[x].eb(i);
    }
    dfs(0);
    FOR(i,q){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        cout<<lca(u,v)+1<<"\n";
    }
}

int main() {
    int tc=1;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    if (betelgeuse) cin>>tc;
    while (tc--) {
        solve();
    }
    return 0;
}
