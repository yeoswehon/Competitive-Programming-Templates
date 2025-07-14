vi minp(MAX_N+1),prime;

void spf(int n){
    for(int i=2;i<=n;i++){
        if (!minp[i]){
            minp[i]=i;
            prime.eb(i);
        }
        for (auto &p:prime){
            if (i*p>n){
                break;
            }
            minp[i*p]=p;
            if (minp[i]==p){
                break;
            }
        }
    }
}
