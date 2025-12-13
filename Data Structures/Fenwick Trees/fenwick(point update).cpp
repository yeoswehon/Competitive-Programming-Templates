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
            ft[x]^=v;
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
            s^=ft[x];
        }
        return s;
    }
 
    T query(int l, int r){ // change conquer
        return sum(r)^sum(l-1);
    }
};
