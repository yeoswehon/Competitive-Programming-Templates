auto f=[&](ll a, ll b) -> ll {
    ll q=a/b;
    ll r=a%b;
    if (r&&((a<0)^(b<0))) q--;
    return q;
};
