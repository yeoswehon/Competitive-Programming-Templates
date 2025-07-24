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
#define VEC(a,n) vector<long double> a(n);for(auto& b:a) cin>>b;
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

void solve() {
    int n;
    cin>>n;
    VEC(a,n);
    vector<dd>dp(n+1); // probability of landing i heads after n tosses
    dp[0]=1;
    FOR(i,n){
        FOR4(j,i+1,1){
            dp[j]=a[i]*dp[j-1]+(1-a[i])*dp[j];
        }
        dp[0]*=(1-a[i]);
    }
    dd ans=0;
    FOR2(i,n/2+1,n+1) ans+=dp[i];
    cout<<fixed<<setprecision(10);
    anslol;
}

int main() {
    int tc=1;
    ios::sync_with_stdio(false);cin.tie(nullptr);
    while (tc--) {
        solve();
    }
    return 0;
}
