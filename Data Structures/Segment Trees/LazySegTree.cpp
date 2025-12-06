// array 1-based indexing, INIT: Node<ll> st(arr,1,n)
template<typename T> // 1-based indexing
struct Node{
    int lo,hi;
    T val,mset,madd;
    Node *l,*r;

    static constexpr T NEG_INF=numeric_limits<T>::lowest();
    static constexpr T NONE=numeric_limits<T>::max();

    T conquer(const T&a,const T&b){
        return a+b;
    }

    Node(int lo,int hi)
        :lo(lo),hi(hi),val(NEG_INF),mset(NONE),madd(T{}),l(nullptr),r(nullptr){}

    Node(vector<T>&v,int lo,int hi):Node(lo,hi){
        if(lo==hi){val=v[lo];return;}
        int mid=(lo+hi)>>1;
        l=new Node(v,lo,mid);
        r=new Node(v,mid+1,hi);
        val=conquer(l->val,r->val);
    }

    void apply_set(T x){
        mset=x;
        madd=T{};
        val=x;
    }

    void apply_add(T x){
        if(mset!=NONE)mset+=x;
        else madd+=x;
        val+=x;
    }

    void propagate(){
        if(!l){
            int mid=(lo+hi)>>1;
            l=new Node(lo,mid);
            r=new Node(mid+1,hi);
        }
        if(mset!=NONE){
            l->apply_set(mset);
            r->apply_set(mset);
            mset=NONE;
        }
        if(madd!=T{}){
            l->apply_add(madd);
            r->apply_add(madd);
            madd=T{};
        }
    }

    T query(int L,int R){
        if(R<lo||hi<L)return NEG_INF;
        if(L<=lo&&hi<=R)return val;
        propagate();
        return conquer(l->query(L,R),r->query(L,R));
    }

    void setrange(int L,int R,T x){
        if(R<lo||hi<L)return;
        if(L<=lo&&hi<=R){apply_set(x);return;}
        propagate();
        l->setrange(L,R,x);
        r->setrange(L,R,x);
        val=conquer(l->val,r->val);
    }

    void addrange(int L,int R,T x){
        if(R<lo||hi<L)return;
        if(L<=lo&&hi<=R){apply_add(x);return;}
        propagate();
        l->addrange(L,R,x);
        r->addrange(L,R,x);
        val=conquer(l->val,r->val);
    }
};
