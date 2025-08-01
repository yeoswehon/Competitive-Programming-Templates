// remember to mint::init(MAX_N);
struct mint {
    inline static ll MOD = MOD; // change
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
    inline static vector<mint>F,I;
    static void init(int MAX){
        F.resize(MAX+1);
        I.resize(MAX+1);
        F[0]=1;
        for(int i=1;i<=MAX;i++) F[i]=F[i-1]*i;
        I[MAX]=F[MAX].inv();
        for(int i=MAX;i>0;i--) I[i-1]=I[i]*i;
    }
    static mint C(int n,int k){
        if(k<0||k>n)return 0;
        return F[n]*I[k]*I[n-k];
    }
};
