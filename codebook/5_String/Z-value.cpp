vi z_value(string s) {
    int n = s.size(), b = 0;
    vi z(n);
    for(int i=1; i<n; ++i) {
        if(z[b]+b < i) z[i] = 0;
        else z[i] = min(z[b]+b-i, z[i-b]);
        while(s[z[i]] == s[z[i]+i]) z[i]++;
        if(z[i]+i > z[b]+b) b = i;
    }
    return z;
}