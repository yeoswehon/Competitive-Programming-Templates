template<typename T>
struct RMQ {
    int n,L;
    vector<int>lg;
    vector<vector<T>>st;
    T conquer(T&a,T&b) {
        return min(a,b);
    }
    RMQ(vector<T>&v) {
        n=v.size();
        lg.assign(n+1,0);
        for (int i=2;i<=n;i++){
            lg[i]=lg[i>>1]+1;
        }
        L=lg[n];
        st.assign(L+1,vector<T>(n));
        st[0]=v;
        for (int k=1;k<=L;k++) {
            for (int i=0;i+(1<<k)-1<n;i++) {
                st[k][i]=conquer(st[k-1][i],st[k-1][i+(1<<(k-1))]);
            }
        }
    }
    T query(int l,int r){ // 0-based
        int k=lg[r-l+1];
        return conquer(st[k][l],st[k][r-(1<<k)+1]);
    }
};
