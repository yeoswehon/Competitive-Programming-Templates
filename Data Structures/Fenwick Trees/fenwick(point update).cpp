template<typename T=int> // 1-based
struct FEN{
    int n;
    vector<T> ft;
    FEN(int m):n(m),ft(m+1,T()){}

    void update(int x,T v){
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

    T sum(int x){
        T s=T(); 
        for(;x;x-=(x&(-x))){
            s+=ft[x];
        }
        return s;
    }

    T query(int l, int r){
        return sum(r)-sum(l-1);
    }
};
