template<typename T>
struct RMQIDX {
    int n,L;
    vector<int>lg;
    vector<vector<int>>st;
    vector<T>a;

    T conquer(int x,int y){
        return (a[x]>a[y]?x:y);
    }

    RMQ(vector<T>&v):a(v) {
        n=v.size();
        lg.assign(n+1,0);
        for (int i=2;i<=n;i++){
            lg[i]=lg[i>>1]+1;
        }
        L=lg[n];
        st.assign(L+1,vector<int>(n));
        for (int i=0;i<n;i++) st[0][i]=i;
        for (int k=1;k<=L;k++) {
            for (int i=0;i+(1<<k)-1<n;i++){
                st[k][i]=conquer(st[k-1][i],st[k-1][i+(1<<(k-1))]);
            }
        }
    }

    int query(int l,int r){ // 0-based
        int k=lg[r-l+1];
        return conquer(st[k][l],st[k][r-(1<<k)+1]);
    }
};
