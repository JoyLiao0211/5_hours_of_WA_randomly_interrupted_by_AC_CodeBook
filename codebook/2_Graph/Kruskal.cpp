using Edge = array<ll, 3>;  // w, u, v
vector<Edge> edges;

ll mst(){
    sort(all(edges));
    DSU dsu(n);
    ll ret = 0;
    for(auto &[w, u, v]: edges) if(dsu.merge(u, v)) ret += w;
    return ret;
}