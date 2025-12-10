template<typename T,int MAXB=32>
struct BitwiseTrie{
    struct Node{
        int ch[2];
        int cnt;
        Node(){ch[0]=ch[1]=-1;cnt=0;}
    };
    vector<Node> t;
    BitwiseTrie(){t.eb(Node());}

    bool empty()const{return t[0].cnt==0;}

    void modify(T x,int freq){
        if(!freq)return;
        int v=0;
        t[v].cnt+=freq;
        for(int i=MAXB;i>=0;--i){
            int bit=(x>>i)&1;
            int &nxt=t[v].ch[bit];
            if(nxt==-1){
                if(freq>0){
                    nxt=(int)t.size();
                    t.push_back(Node());
                } else return;
            }
            v=nxt;
            t[v].cnt+=freq;
        }
    }

    void add(T x,int freq=1){modify(x,freq);}
    void remove(T x,int freq=1){modify(x,-freq);}

    // min(x^y)
    T min_xor(T x)const{
        if(empty())return numeric_limits<T>::max();
        int v=0;
        T res=0;
        for(int i=MAXB;i>=0;--i){
            int bit=(x>>i)&1;
            int oppbit=bit^1;
            int nxt=t[v].ch[bit];
            if(nxt!=-1&&t[nxt].cnt>0){
                v=nxt;
            }else{
                nxt=t[v].ch[oppbit];
                v=nxt;
                res|=(T(1)<<i);
            }
        }
        return res;
    }

    // max(x^y)
    T max_xor(T x)const{
        if(empty())return 0;
        int v=0;
        T res=0;
        for(int i=MAXB;i>=0;--i){
            int bit=(x>>i)&1;
            int oppbit=bit^1;
            int nxt=t[v].ch[oppbit];
            if(nxt!=-1&&t[nxt].cnt>0){
                v=nxt;
                res|=(T(1)<<i);
            }else{
                nxt=t[v].ch[bit];
                v=nxt;
            }
        }
        return res;
    }
};
