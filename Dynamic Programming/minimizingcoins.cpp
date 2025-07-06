#include <bits/stdc++.h> // https://cses.fi/problemset/task/1634
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

void solve() {
    int n,x;
    cin>>n>>x;
    VEC(a,n);
    vl dp(x+1,INF);
    dp[0]=0;
    for(int i=1;i<=x;i++){
        FOR(j,n){
            if (i-a[j]>=0){
                chmin(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    if (dp[x]==INF){
        cout<<-1<<"\n";
    } else cout<<dp[x]<<"\n";
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
