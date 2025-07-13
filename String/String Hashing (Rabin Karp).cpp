// Problem: Given two strings - a pattern s and a text t, determine if the pattern appears in the text and if it does, enumerate all its occurrences in  O(|s| + |t|)  time.
// Time Complexity: O(n + m)
#include <bits/stdc++.h> // https://cses.fi/problemset/task/1753/
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
const ll MAX_N=300000;
const ll MOD2=1000000007;
const ll INF=1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand_ll(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

const ll BASE=rand_ll(256, 1000000000);
static const int K=2;
const array<ll,K> MODS={1000000007LL, 1000000009LL};

struct Hash {
    ll base;
    array<ll,K> mod;
    vector<ll> h[K],p[K];

    Hash(string &s, ll base=BASE, array<ll,K> mod=MODS) // rolling hash
        : base(base), mod(mod) {
        int n=s.size();
        for (int k=0;k<K;k++) {
            h[k].assign(n+1,0);
            p[k].assign(n+1,1);
            for (int i=0;i<n;i++){
                h[k][i+1]=(h[k][i]*base+(s[i]-'a'+1))%mod[k]; // h[k][i+1]= s[0]*b^i + s[1]*b^(i-1) + ...
                p[k][i+1]=(p[k][i]*base)%mod[k];
            }
        }
    }

    array<ll,K> query(int l, int r){ // 0-based, hash[l...r]
        array<ll,K> res;
        for (int k=0;k<K;k++) {
            ll x=(h[k][r+1]-(h[k][l]*p[k][r-l+1]))%mod[k];
            if (x<0) x+=mod[k];
            res[k]=x;
        }
        return res;
    }
};

void solve() {
    string t,s;
    cin>>t>>s;
    int n=t.sz, m=s.sz;
    if (m>n){
        cout<<0<<"\n";
        return;
    }
    Hash tt(t), xx(s);
    auto ni=xx.query(0,m-1); // array<ll,2> ds
    int ans=0;
    for(int i=0;i+m-1<=n-1;i++){
        if (tt.query(i,i+m-1)==ni){
            ans++;
        }
    }
    cout<<ans<<"\n";
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
