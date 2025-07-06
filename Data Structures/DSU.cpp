class DSU{
private:
    vi p,rank,setsize;
    int cnt;
public:
    DSU(int n){
        p.assign(n+1,0);
        for (int i=1;i<=n;i++) p[i]=i;
        rank.assign(n+1,0);
        setsize.assign(n+1,1);
        cnt=n;
    }
    int find(int i) {return (p[i]==i)?i:p[i]=find(p[i]);}
    bool same(int i, int j) {return find(i)==find(j);}
    int numset(){return cnt;}
    int setsz(int i){return setsize[find(i)];}
    bool parent(int i){return find(i)==i;}

    void unite(int i,int j){
        if (same(i,j))return;
        int x=find(i);int y=find(j);
        if (rank[x]>rank[y])swap(x,y);
        p[x]=y;
        if (rank[x]==rank[y]) rank[y]++;
        setsize[y]+=setsize[x];
        cnt--;
    }
};
