struct cmp {
    bool operator()(T a, T b) const {
        return 0;
    }
};
priority_queue<T, vector<T>, cmp> pq;
set<T, cmp> st;