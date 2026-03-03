// sgn(x): returns -1/0/+1 by sign of x
// dot(p): x·p (projection/angle info)
// cross(p): z-component of x×p (signed area/orientation)
// cross(a,b): (a-*this)x(b-*this); sign = left/right/collinear turn at *this
// dist2(): squared length |p|^2 (no sqrt)
// dist(): length |p|
// angle(): atan2(y,x) in [-pi,pi]
// unit(): p normalised to length 1
// perp(): rotate +90° (-y,x)
// normal(): unit perpendicular
// rotate(a): rotate by a radians CCW about origin

template<class T> constexpr int sgn(T x){return (T(0)<x)-(x<T(0));}

template<class T>
struct Point{
  using P=Point;
  T x,y;
  explicit Point(T x=0,T y=0):x(x),y(y){}

  bool operator<(const P& p)const{return x<p.x || (x==p.x && y<p.y);}
  bool operator==(const P& p)const{return x==p.x && y==p.y;}

  P operator+(const P& p)const{return P(x + p.x, y + p.y);}
  P operator-(const P& p)const{return P(x - p.x, y - p.y);}
  P operator*(T d)const{return P(x * d, y * d);}
  P operator/(T d)const{return P(x / d, y / d);}

  T dot(const P& p)const{return x * p.x + y * p.y;}
  T cross(const P& p)const{return x * p.y - y * p.x;}
  T cross(const P& a,const P& b)const{return (a - *this).cross(b - *this);}

  T dist2()const{return x * x + y * y;}
  double dist()const{return sqrt((double)dist2());}
  double angle()const{return atan2((double)y,(double)x);}

  P unit()const{return *this/dist();}
  P perp()const{return P(-y,x);} // +90°
  P normal()const{return perp().unit();}

  P rotate(double a)const{
    double c=cos(a),s=sin(a);
    return P(x * c - y * s, x * s + y * c);
  }

  friend ostream& operator<<(ostream& os,const P& p){
    return os<<"("<<p.x<<","<<p.y<<")";
  }
};
