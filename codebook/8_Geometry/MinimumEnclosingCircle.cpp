using ld = long double;
mt19937 rng(950223);  // O(n) expected time
pair<pdd, ld> minimumEnclosingCircle(vector<pdd> &pts){
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
					auto [c, r] = circenter(pts[i], pts[j], pts[k]);
			}
		}
	}
	return {c, r};
}