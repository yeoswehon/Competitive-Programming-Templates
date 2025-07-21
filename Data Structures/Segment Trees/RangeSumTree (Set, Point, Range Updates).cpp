template<typename T> // 0-based
class RangeSumTree{
    int n;
    vector<T>A,st,lazy_add,lazy_set;
    vector<bool>has_set;

    T conquer(const T&a,const T&b){
        return a+b;
    }

    void build(int p,int l,int r){
        if(l==r) st[p]=A[l];
        else{
            int m=l+(r-l)/2;
            build(p<<1,l,m);build(p<<1|1,m+1,r);
            st[p]=conquer(st[p<<1],st[p<<1|1]);
        }
    }

    void propagate(int p,int l,int r){
        if(has_set[p]){
            st[p]=lazy_set[p]*(r-l+1);
            if(l!=r){
                has_set[p<<1]=has_set[p<<1|1]=1;
                lazy_set[p<<1]=lazy_set[p<<1|1]=lazy_set[p];
                lazy_add[p<<1]=lazy_add[p<<1|1]=T{};
            }
            has_set[p]=0;
        }
        if(lazy_add[p]!=T{}){
            st[p]+=lazy_add[p]*(r-l+1);
            if(l!=r){
                lazy_add[p<<1]+=lazy_add[p];
                lazy_add[p<<1|1]+=lazy_add[p];
            }
            lazy_add[p]=T{};
        }
    }

    T rq(int p,int l,int r,int i,int j){
        propagate(p,l,r);
        if(j<l||r<i) return T{};
        if(i<=l&&r<=j) return st[p];
        int m=l+(r-l)/2;
        return conquer(rq(p<<1,l,m,i,j),rq(p<<1|1,m+1,r,i,j));
    }

    void update_add(int p,int l,int r,int i,int j,T v){
        propagate(p,l,r);
        if(j<l||r<i)return;
        if(i<=l&&r<=j){
            lazy_add[p]+=v;
            propagate(p,l,r);
        }
        else{
            int m=l+(r-l)/2;
            update_add(p<<1,l,m,i,j,v);
            update_add(p<<1|1,m+1,r,i,j,v);
            st[p]=conquer(st[p<<1],st[p<<1|1]);
        }
    }

    void update_set(int p,int l,int r,int i,int j,T v){
        propagate(p,l,r);
        if(j<l||r<i) return;
        if(i<=l&&r<=j){
            has_set[p]=1;
            lazy_set[p]=v;
            lazy_add[p]=T{};
            propagate(p,l,r);
        }
        else{
            int m=l+(r-l)/2;
            update_set(p<<1,l,m,i,j,v);
            update_set(p<<1|1,m+1,r,i,j,v);
            st[p]=conquer(st[p<<1],st[p<<1|1]);
        }
    }

public:
    RangeSumTree(int n):n(n),A(n,T{}),st(4*n,T{}),lazy_add(4*n,T{}),lazy_set(4*n,T{}),has_set(4*n,0){}
    RangeSumTree(vector<T>&a):RangeSumTree((int)a.size()){A=a;build(1,0,n-1);A.clear();}
    void addrange(int x,int y,T v){update_add(1,0,n-1,x,y,v);}
    void setrange(int x,int y,T v){update_set(1,0,n-1,x,y,v);}
    T query(int x,int y){return rq(1,0,n-1,x,y);}
};
