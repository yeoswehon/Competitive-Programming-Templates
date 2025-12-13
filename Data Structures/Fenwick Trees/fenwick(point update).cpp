template<typename T=ll> // 1-based
struct FEN{
    int n;
    int mx;
    vector<T>ft;
 
    FEN(int m):n(m),ft(m+1,T()) {
        mx=1;
        while(mx*2<=n) mx<<=1;
    }
 
    void update(int x,T v){ // change conquer
        for(;x<=n;x+=(x&(-x))){
            ft[x]+=v;
        }
    }
    
    void build(vector<T>& a){
        n=int(a.size());
        ft.assign(n+1,T());
        for(int i=0;i<n;i++){
            update(i+1,a[i]);
        }
    }
 
    T sum(int x){ // change conquer
        T s=T(); 
        for(;x;x-=(x&(-x))){
            s+=ft[x];
        }
        return s;
    }
 
    T query(int l, int r){ // change conquer
        return sum(r)-sum(l-1);
    }

    // returns smallest idx (1-based) such that prefix sum >= k
    T kth(T k){
        T x=0;
        for(T i=(T(1)<<__lg(n));i;i>>=1){
            if(x+i<=n && ft[x+i]<k){
                x+=i;
                k-=ft[x];
            }
        }
        return x+1;
    }

};
