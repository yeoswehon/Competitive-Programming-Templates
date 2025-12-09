// Returns x0 and y0 such that a*x0 + b*y0 = gcd(a,b)
template<typename T>pair<T,T>egcd(T a,T b){
    if(!b)return{1,0};
    auto[x1,y1]=egcd(b,a%b);
    T x=y1;
    T y=x1-a/b*y1;
    return{x,y};
}
