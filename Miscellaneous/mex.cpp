// Time Complexity: O(n)
template<typename T>
T mex(const vector<T>& a,int &n) { // set n = MAX_N
    vector<bool>seen(n+1);
    for (T &x:a) {
        if (x>=0&&x<=n) seen[x]|=1;
    }
    for (int i=0;i<=n;i++)
        if (!seen[i]) return i;
    return n+1;
}
