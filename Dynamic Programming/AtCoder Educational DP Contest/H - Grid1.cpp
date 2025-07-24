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
#define VEC(a,n) vector<int> a(n);for(auto& b:a) cin>>b;
#define sz size()
#define anslol cout<<ans<<"\n"
#define all(x) x.begin(),x.end()
#define newline cout<<endl
#define debug(v) cout<<"Line(" << __LINE__ << ") -> "<<#v<<" = "<<(v)<<"\n";
template <typename T>void print(const vector<T>&v){for (const T&x:v)cout<<x<<" ";cout<<"\n";}
template<class T,class S>inline bool chmax(T&a,const S&b){return(a<b?a=b,1:0);}
template<class T,class S>inline bool chmin(T&a,const S&b){return(a>b?a=b,1:0);}

const ll MAX_N=300000;
const ll MOD2=1000000007;
const ll INF=1e18;

struct mint {
    inline static ll MOD = MOD2; // change
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
    int r,c;
    cin>>r>>c;
    vector<string>a(r);
    read(a);
    vector<vector<mint>>dp(r,vector<mint>(c));
    dp[0][0]=1;
    FOR(i,r){
        if (a[i][0]=='#') break;
        dp[i][0]=1;
    }
    FOR(i,c){
        if (a[0][i]=='#') break;
        dp[0][i]=1;
    }
    FOR2(i,1,r){
        FOR2(j,1,c){
            if (a[i][j]=='.'){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[r-1][c-1]<<"\n";
}

int main() {
    int tc=1;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    while (tc--) {
        solve();
    }
    return 0;
}
