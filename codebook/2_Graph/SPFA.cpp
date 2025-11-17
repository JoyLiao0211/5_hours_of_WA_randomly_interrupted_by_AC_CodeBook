vector<pii> g[N];
bool inq[N];
ll d[N];
int cnt[N], len[N], p[N];

bool spfa(int s, int n){
    fill_n(d, n, LINF);
    fill_n(p, n, -1);
    deque<int> q;
    d[s] = 0;
    q.eb(s);
    inq[s] = true;
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        inq[u] = false;
        cnt[u]++;
        if(cnt[u] >= n) return false;
        if(p[u] != -1 && inq[p[u]]) continue;
        for(auto [v, w] : g[u]){
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                p[v] = u;
                if(!inq[v]){
                    if (!q.empty() && d[v] < d[q.front()]) q.emplace_front(v);
                    else q.eb(v);
                    inq[v] = true;
                    len[v] = len[u] + 1;
                    if(len[v] >= n) return false;
                }
            }
        }
    }
    return true;
}