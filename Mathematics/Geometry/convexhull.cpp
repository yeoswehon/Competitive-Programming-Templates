template<class T>struct Point{
  typedef Point P;
  T x,y;
  Point(T x=0,T y=0):x(x),y(y){}
  bool operator<(P p)const{return x<p.x || (x==p.x && y<p.y);}
  bool operator==(P p)const{return x==p.x && y==p.y;}
  T cross(P a,P b)const{return (a.x-x) * (b.y-y) - (a.y-y) * (b.x-x);} // OA -> OB (a-*this)x(b-*this): >0 ccw/left, <0 cw/right, =0 collinear
};

typedef Point<ll> P;

vector<P>convexHull(vector<P>pts){
  UNIQUE(pts);
  if(pts.sz<=1)return pts;
  vector<P>h;
  FOR(it,2){
    ll s=h.sz;
    for(P p:pts){
      while(h.sz>=s+2 && h[h.sz-2].cross(h[h.sz-1],p)<=0) h.pop_back();
      h.pb(p);
    }
    h.pop_back();
    reverse(all(pts));
  }
  return h;
}
