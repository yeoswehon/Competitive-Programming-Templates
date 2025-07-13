// while loop
template<typename T>
T BK(T n, int k) {
    T r=0,p=1;
    while (n) {
        r+= p*(n%k);
        p*=10;
        n/=k;
    }
    return r;
}

// for loop
template<typename T>
T BK(T n, int k) {
    T r=0,p=1;
    for (;n;n/= k,p *= 10)
        r+= p*(n%k);
    return r;
}
