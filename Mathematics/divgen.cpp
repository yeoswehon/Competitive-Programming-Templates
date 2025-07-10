template<typename T> 
vector<T> divisors(T n) {
    vector<T> res;
    for (T d=1;d*d<=n;d++) {
        if (n%d==0) {
            res.eb(d);
            if (d*d!=n)
                res.eb(n/d);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
