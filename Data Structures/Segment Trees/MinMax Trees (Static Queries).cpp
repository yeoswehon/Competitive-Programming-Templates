template<typename T,class Op> // 0-based
class SegTree{
  long long n,N;
  vector<T>st;
  Op op;
public:
  SegTree(const vector<T>&a){
    n=a.size();
    N=1;while(N<n)N<<=1;
    st.assign(2*N,Op::identity());
    for(int i=0;i<n;i++)st[N+i]=a[i];
    for(int i=N-1;i;i--)st[i]=op(st[i<<1],st[i<<1|1]);
  }
  void update(int p,T v){
    for(st[p+=N]=v;p>1;p>>=1)st[p>>1]=op(st[p],st[p^1]);
  }
  T query(int l,int r){
    T res=Op::identity();
    for(l+=N,r+=N;l<=r;l>>=1,r>>=1){
      if(l&1)res=op(res,st[l++]);
      if(r%2==0)res=op(st[r--],res);
    }
    return res;
  }
  // [l,r], value, op, bool returns index
  int find(int l,int r,T x,const string&op,bool rightmost){ // MAX TREE [>=, >], nearest neighbour leftmost or rightmost
    bool sgn=(op==">");
    return find(1,0,N-1,l,r,x,sgn,rightmost);
  }
private:
  int find(int p,int L,int R,int ql,int qr,T x,bool sgn,bool rightmost){ // MAX TREE ONLY
    if(R<ql||qr<L)return-1;
    T v=st[p];
    if(sgn?v<=x:v<x)return-1;
    if(L==R)return L;
    int m=(L+R)>>1;
    if(!rightmost){
      int res=find(p<<1,L,m,ql,qr,x,sgn,rightmost);
      return res!=-1?res:find(p<<1|1,m+1,R,ql,qr,x,sgn,rightmost);
    }else{
      int res=find(p<<1|1,m+1,R,ql,qr,x,sgn,rightmost);
      return res!=-1?res:find(p<<1,L,m,ql,qr,x,sgn,rightmost);
    }
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
