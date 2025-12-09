// Returns x0 and y0 such that a*x0 + b*y0 = gcd(a,b)
auto egcd=[&](auto &&self, ll a,ll b, ll &x0, ll &y0) -> ll{
    if (!b) return x0=1,y0=0,a;
    ll d=self(self,b,a%b,y0,x0);
    return y0-=(a/b)*x0,d;
};
