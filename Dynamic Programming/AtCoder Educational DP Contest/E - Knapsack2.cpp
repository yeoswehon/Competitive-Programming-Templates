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
const ll MOD=1000000007;
const ll INF=1e18;

void solve() {
    ll n,W;
    cin>>n>>W;
    vl w(n),v(n);
    FOR(i,n){
        cin>>w[i]>>v[i];
    }
    ll sum=SUM(v);
    vl dp(sum+1,INF); // dp[i] at the i-th value, what is my minimum weight
    dp[0]=0;
    FOR(i,n){
        FOR4(j,sum,v[i]){
            if (dp[j-v[i]]!=INF) chmin(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    FOR3(i,sum){
        if (dp[i]<=W){
            cout<<i<<"\n";
            return;
        }
    }
}

int main() {
    int tc=1;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    while (tc--) {
        solve();
    }
    return 0;
}
