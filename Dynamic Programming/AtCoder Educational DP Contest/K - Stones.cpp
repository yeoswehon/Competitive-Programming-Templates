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

const ll MAX_N=302;
const ll MOD2=1000000007;
const ll INF=1e18;

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<bool>dp(k+1); // dp[i] = win for player 1 with i stones remaining
    dp[0]=0;
    VEC(a,n);
    FOR(i,k+1){
        for(auto &x:a){
            if (!dp[i-x]&&i-x>=0){
                dp[i]=1;
            }
        }
    }
    if (dp[k]) cout<<"First"<<"\n";
    else cout<<"Second"<<"\n";
}

int main() {
    int tc=1;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    while (tc--) {
        solve();
    }
    return 0;
}
