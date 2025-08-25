template<class T, T (*op)(T, T), T (*e)()>
struct segtree {
    int n, sz;
    vector<T> d;
    explicit segtree(int n): segtree(vector<T>(n, e())) {}
    explicit segtree(const vector<T> &v) {
        n = v.size(), sz = 1;
        while(sz < n) sz <<= 1;
        d.assign(sz*2, e());
        for(int i=0; i<n; ++i) d[sz+i] = v[i];
        for(int i=sz-1; i>=1; --i) d[i] = op(d[i<<1], d[i<<1|1]);
    }
    void set(int p, const T &x) {
        p += sz, d[p] = x;
        while(p>>=1) d[p] = op(d[p<<1], d[p<<1|1]);
    }
    T get(int p) const { return d[sz+p]; }
    T prod(int l, int r) const {
        T sl = e(), sr = e();
        l += sz, r += sz+1;
        while(l < r) {
            if(l&1) sl = op(sl, d[l++]);
            if(r&1) sr = op(d[--r], sr);
            l >>= 1, r >>= 1;
        }
        return op(sl, sr);
    }
};