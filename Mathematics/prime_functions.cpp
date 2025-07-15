vector<ll> primes;

void sieve(int N){ // Sieve from 1 to N (inclusive)
    vector<bool> is_prime(N+1,1);
    is_prime[0]=is_prime[1]=0;
    for (int i=2;i*i<=N;i++) {
        if (is_prime[i]) {
            for (int j=i*i;j<=N;j+=i){
                is_prime[j] = false;
            }
        }
    }
    for (int i=2;i<=N;i++) {
        if (is_prime[i]) primes.eb(i);
    }
}

template<typename T> // (prime, exponent)
vector<pair<T,int>> prime_factorise(T n){
    vector<pair<T,int>> res;
    for (ll &p:primes) {
        if ((T)p*p>n) break;
        int c=0;
        while (n%p==0){
            n/=p;
            c++;
        }
        if (c) res.eb((T)p, c);
    }
    if (n>1) res.eb(n,1);
    return res;
}

template<typename T>
int get_prime_exponent(T n){
    auto factors=prime_factorise(n);
    int sum=0;
    for (auto &pr:factors) sum+=pr.ss;
    return sum;
}
