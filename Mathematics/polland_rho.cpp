template<typename T>
T modmul(T a,T b,T m){
    return (T)((__int128)a*b%m);
}

template<typename T>
T modpow(T a,T b,T m){
    T r=1;
    a%=m;
    while(b>0){
        if(b&1)r=modmul(r,a,m);
        a=modmul(a,a,m);
        b>>=1;
    }
    return r;
}

// Check if prime using Miller-Rabin
template<typename T>
bool is_prime(T n){
    if(n<2||n%6%4!=1)return (n|1)==3;
    T A[]={2,325,9375,28178,450775,9780504,1795265022};
    T s=__builtin_ctzll((unsigned long long)(n-1)),d=n>>s;
    for(T a:A){
        T p=modpow(a%n,d,n),i=s;
        while(p!=1&&p!=n-1&&a%n&&i--)p=modmul(p,p,n);
        if(p!=n-1&&i!=s)return 0;
    }
    return 1;
}

// Polland Rho to find a non-trivial factor of n
template<typename T>
T rho(T n){
    if(!(n&1))return 2;
    T x=0,y=0,prd=2,q,i=1;
    int t=30;
    auto f=[&](T v){return (modmul(v,v,n)+i)%n;};
    while(t++%40||__gcd((ll)prd,(ll)n)==1){
        if(x==y)x=++i,y=f(x);
        T diff=x>y?x-y:y-x;
        if((q=modmul(prd,diff,n)))prd=q;
        x=f(x);y=f(f(y));
    }
    return __gcd((ll)prd,(ll)n);
}

// Factor n into prime factors with Polland Rho with MULTIPLICTY!!, sorted
template<typename T>
vector<T> factor_rho_raw(T n){
    vector<T> res;
    if(n<=1)return res;
    auto solve=[&](auto self,T v)->void{
        if(v==1)return;
        if(is_prime(v)){res.eb(v);return;}
        T d=v;
        while(d==v)d=rho(v);
        self(self,d);
        self(self,v/d);
    };
    solve(solve,n);
    sort(res.begin(),res.end());
    return res;
}

// Grouped (prime,exponent)
template<typename T>
vector<pair<T,int>> prime_factorise_rho(T n){
    vector<T> f=factor_rho_raw(n);
    vector<pair<T,int>> res;
    for(T p:f){
        if(res.empty()||res.back().ff!=p)res.eb(p,1);
        else res.back().ss++;
    }
    return res;
}

// Total no of prime factors with multiplicity
template<typename T>
int get_prime_exponent_rho(T n){
    auto fac=prime_factorise_rho(n);
    int s=0;
    for(auto &pr:fac)s+=pr.ss;
    return s;
}

// Divisors using rho
template<typename T>
vector<T> divisors_rho(T n){
    vector<pair<T,int>> pf=prime_factorise_rho(n);
    vector<T> res;
    res.eb((T)1);
    for(auto &pr:pf){
        T p=pr.ff;
        int e=pr.ss;
        int m=res.size();
        T cur=1;
        for(int k=1;k<=e;k++){
            cur*=p;
            for(int i=0;i<m;i++)res.eb(res[i]*cur);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
