pair<pdd, ld> circenter(pdd a, pdd b, pdd c){ // SCOPE HASH
  pdd m1 = (a+b)/2, m2 = (b+c)/2; 
  pdd cent = intersect(m1, m1 + perp(b-a), m2, m2 + perp(c-b));
  return {cent, abs(a-cent)};
}
pair<pdd, ld> incenter(pdd p1, pdd p2, pdd p3) { // radius = area / s * 2
  ld a = abs(p2 - p3), b = abs(p1 - p3), c = abs(p1 - p2);
  pdd cent = (a * p1 + b * p2 + c * p3) / (a + b + c);
  return {cent, abs(a-cent)};
}
pdd masscenter(pdd p1, pdd p2, pdd p3) 
{ return (p1 + p2 + p3) / 3; }
pdd orthcenter(pdd p1, pdd p2, pdd p3) 
{ return masscenter(p1, p2, p3) * 3 - circenter(p1, p2, p3) * 2; }
