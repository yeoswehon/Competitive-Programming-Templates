template<typename T>
ll invcnt(vector<T>& a) {
    int n=a.size();
    vector<T> tmp(n);
    auto rec=[&](auto &&self,int l,int r) -> ll {
        if (l>=r) return 0;
        int m=l+((r-l)>>1);
        ll inv=self(self,l,m)+self(self,m+1,r);
        int i=l,j=m+1,k=l;
        while (i<=m&&j<=r) {
            if (a[i]<=a[j])tmp[k++]=a[i++];
            else {
                tmp[k++]=a[j++];
                inv+=(m-i+1);
            }
        }
        while (i<=m) tmp[k++]=a[i++];
        while (j<=r) tmp[k++]=a[j++];
        for (int p=l;p<=r;p++)a[p]=tmp[p];
        return inv;
    };
    return rec(rec,0,n-1);
}
