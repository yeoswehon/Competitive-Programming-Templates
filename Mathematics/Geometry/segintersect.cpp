// orient(a,b,c): signed turn of a->b->c (+ccw, -cw, 0 collinear).
// onSegment(a,b,p): true iff p lies on segment [a,b] (endpoints included).
// segIntersect(a,b,c,d): true iff segments [a,b] and [c,d] intersect (touch/overlap included).

template<class T>struct Point{
  using P=Point;
  T x,y;
  Point(T x=0,T y=0):x(x),y(y){}
  P operator-(P p)const{return P(x-p.x,y-p.y);}
  T cross(P p)const{return x*p.y-y*p.x;}
};

template<class P> auto orient(P a,P b,P c){return (b-a).cross(c-a);}

template<class P> bool onSegment(P a,P b,P p){
  return sgn(orient(a,b,p))==0 && (min(a.x,b.x) <= p.x && p.x <= max(a.x,b.x)
                               && min(a.y,b.y) <= p.y && p.y <= max(a.y,b.y));
}

template<class P> bool segIntersect(P a,P b,P c,P d){
  int o1=sgn(orient(a,b,c)), o2=sgn(orient(a,b,d));
  int o3=sgn(orient(c,d,a)), o4=sgn(orient(c,d,b));
  if(o1==0 && onSegment(a,b,c))return 1;
  if(o2==0 && onSegment(a,b,d))return 1;
  if(o3==0 && onSegment(c,d,a))return 1;
  if(o4==0 && onSegment(c,d,b))return 1;
  return o1*o2<0&&o3*o4<0;
}
