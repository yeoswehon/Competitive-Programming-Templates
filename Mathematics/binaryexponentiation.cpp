ll binpow_rec(ll a, ll b) { // recursive
    if (b == 0) return 1;
    ll r = binpow_rec(a, b >> 1);
    r = r * r;
    if (b & 1) r *= a;
    return r;
}

ll binpow(ll a, ll b) { // iterative
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll modpow(ll a, ll b, ll m = MOD) { // iterative with mod
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
