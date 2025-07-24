#include <bits/stdc++.h>
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
#define FOR2(i,a,b) for(ll i=(a);i<ll(b);i++)
#define FOR3(i,n) for(ll i=(n);i>=ll(0);i--)
#define FOR4(i,a,b) for(ll i=(a);i>=ll(b);i--)
#define SUM(a) accumulate((a).begin(),(a).end(),0LL)
#define SORT(a) sort(a.begin(),a.end())
#define RSORT(a) sort(a.rbegin(),a.rend())
#define UNIQUE(a) sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end()); // sorting included
#define VEC(a,n) vector<long long> a(n);for(auto& b:a) cin>>b;
#define vec(a,n) vector<int> a(n);for(auto& b:a) cin>>b;
#define sz size()
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define anslol cout<<ans<<"\n"
#define all(x) x.begin(),x.end()
#define newline cout<<endl
#define debug(v) cout<<"Line(" << __LINE__ << ") -> "<<#v<<" = "<<(v)<<"\n";
template<typename T>void print(const vector<T>&v){for (const T&x:v)cout<<x<<" ";cout<<"\n";}
template<typename T>void print(const T&x){cout<<x<<"\n";}
template<class T,class S>inline bool chmax(T&a,const S&b){return(a<b?a=b,1:0);}
template<class T,class S>inline bool chmin(T&a,const S&b){return(a>b?a=b,1:0);}
template<typename T>T floor(T a,T b){return a/b-((a%b)&&((a^b)<0));}
template<typename T>T ceil(T x,T y){return floor(x+y-1,y);}
int topbit(int x){return x==0?-1:31-__builtin_clz(x);}
int topbit(ll x){return x==0?-1:63-__builtin_clzll(x);}

bool betelgeuse=0;
const ll MAX_N=300000;
const ll MOD=1000000007;
const ll INF=1e18;

void solve() {
    int n,m;
    cin>>n>>m;
    vi in(n);
    vector<bool>vis(n);
    vector<vl> adj(n);
    FOR(i,m){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        in[v]++;
        adj[u].eb(v);
    }
    vi dp(n);
    auto dfs=[&](auto &&self, auto &u) -> void {
        vis[u]=1;
        for(auto &v:adj[u]){
            chmax(dp[v],dp[u]+1);
            in[v]--;
            if (!in[v]) self(self,v);
        }
    };
    FOR(i,n){
        if (!in[i] && !vis[i]){
            dfs(dfs,i);
        }
    }
    ll ans=*max_element(all(dp));
    anslol;
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
