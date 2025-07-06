#include <bits/stdc++.h> // https://cses.fi/problemset/task/1636/
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

struct mint {
    inline static ll MOD = MOD2;
    ll v;
    static void set_mod(ll mod) { MOD = mod; }
    mint() : v(0) {}
    mint(ll x) { v = x % MOD; if(v < 0) v += MOD; }
    mint pow(ll power) const {
        mint res(1), base(*this);
        while(power > 0){
            if(power & 1) res *= base;
            base *= base; power >>=1;
        }
        return res;
    }
    mint inv() const { return this->pow(MOD - 2); }
    mint& operator+=(const mint& o) { v += o.v; if(v >= MOD) v -= MOD; return *this; }
    mint& operator-=(const mint& o) { if(v < o.v) v += MOD; v -= o.v; return *this; }
    mint& operator*=(const mint& o) { v = (__int128(v) * o.v) % MOD; return *this; }
    mint& operator/=(const mint& o) { return (*this) *= o.inv(); }
    mint operator-() const { return mint(0) - *this; }
    friend mint operator+(mint a, const mint& b) { a += b; return a; }
    friend mint operator-(mint a, const mint& b) { a -= b; return a; }
    friend mint operator*(mint a, const mint& b) { a *= b; return a; }
    friend mint operator/(mint a, const mint& b) { a /= b; return a; }
    friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { return a.v != b.v; }
    friend ostream& operator<<(ostream& os, const mint& x) { return os << x.v; }
    friend istream& operator>>(istream& is, mint& x) { ll tmp; is >> tmp; x = mint(tmp); return is; }
};

void solve() {
    int n,x;
    cin>>n>>x;
    VEC(a,n);
    vector<mint>dp(x+1);
    dp[0]=1;
    for(auto &y:a){
        for(int i=y;i<=x;i++){
            dp[i]+=dp[i-y];
        }
    }
    cout<<dp[x]<<"\n"; 
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
