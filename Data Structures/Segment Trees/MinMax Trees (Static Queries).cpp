template<typename T,class Op> // 0-based
class SegTree{
  T n;
  vector<T>st;
  Op op;
public:
  SegTree(const vector<T>&a):n((T)a.size()),st(2*n,Op::identity()){
    for(int i=0;i<n;i++)st[n+i]=a[i];
    for(int i=n-1;i;i--)st[i]=op(st[i<<1],st[i<<1|1]);
  }
  void update(int p,T v){
    for(st[p+=n]=v;p>1;p>>=1)st[p>>1]=op(st[p],st[p^1]);
  }
  T query(int l,int r){
    T res=Op::identity();
    for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
      if(l&1)res=op(ans,st[l++]);
      if(r%2==0)res=op(st[r--],res);
    }
    return res;
  }
};

template<typename T>
struct MinOp{
  static T identity(){return numeric_limits<T>::max();}
  T operator()(T a,T b)const{return min(a,b);}
};

template<typename T>
struct MaxOp{
  static T identity(){return numeric_limits<T>::min();}
  T operator()(T a,T b)const{return max(a,b);}
};

template<typename T>using MinSegTree=SegTree<T,MinOp<T>>;
template<typename T>using MaxSegTree=SegTree<T,MaxOp<T>>;
