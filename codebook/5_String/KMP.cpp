vector<int> fail_func(const string &s) {
    int n = s.size();
    vector<int> f(n);
    for(int i=1; i<n; ++i) {
        int j = f[i-1];
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        f[i] = j + (s[i] == s[j]);
    }
    return f;
}
int kmp_count(const string &s, const string &p) {
    int n = s.size(), m = p.size();
    vector<int> f = fail_func(p+"$");
    int cnt = 0, j = 0;
    for(int i=0; i<n; ++i) {
        while(j > 0 && s[i] != p[j]) j = f[j-1];
        j += (s[i] == p[j]);
        if(j == m) cnt++;
    }
    return cnt;
}