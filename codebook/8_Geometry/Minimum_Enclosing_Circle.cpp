using ld = long double;
pair<pdd, ld> circumcenter(pdd a, pdd b, pdd c){
    pdd m1 = (a+b)/2, m2 = (b+c)/2;
    pdd n1 = m1 + perp(b-a), n2 = m2 + perp(c-b);
    pdd cent = intersect(m1, n1, m2, n2);
    return {cent, abs(a-cent)};
}
mt19937 rng(950223);  // O(n) expected time
pair<pdd, ld> MinimumEnclosingCircle(vector<pdd> &pts){
	shuffle(all(pts), rng);
	pdd c = pts[0];
	ld r = 0;
	for(int i = 1; i < SZ(pts); i++){
		if(abs(pts[i] - c) <= r) continue;
		c = pts[i]; r = 0;
		for(int j = 0; j < i; j++){
			if(abs(pts[j] - c) <= r) continue;
			c = (pts[i] + pts[j]) / 2;
			r = abs(pts[i] - c);
			for(int k = 0; k < j; k++){
				if(abs(pts[k] - c) > r)
					tie(c, r) = circumcenter(pts[i], pts[j], pts[k]);
			}
		}
	}
	return {c, r};
}