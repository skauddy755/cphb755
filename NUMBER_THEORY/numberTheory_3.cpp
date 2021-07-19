#include<bits/stdc++.h>
using namespace std;

struct Coeff {
	int fa;
	int fb;
};

Coeff scalarMult(Coeff vec, int k) {
	return {k * vec.fa, k * vec.fb};
}

Coeff add(Coeff v1, Coeff v2) {
	return {v1.fa + v2.fa, v1.fb + v2.fb};
}

int gcd(int a, int b) {
	int rem = a % b;
	if(rem == 0) return b;
	
	return gcd(b, rem);
}

int linComb(int a, int b, Coeff &dd, Coeff &dr) {
	
	int rem = a % b;
	if(rem == 0) return b;
	
	int q = a / b;
	Coeff rv = add(scalarMult(dd, 1), scalarMult(dr, -q));
	dd = dr;
	dr = rv;
	return linComb(b, rem, dd, dr);
}

int inverseModulo(int num, int m) {
	Coeff dd = {1, 0};
	Coeff dr = {0, 1};
	
	int g = linComb(num, m, dd, dr);
	if(g != 1) return 0;
	int ans = dr.fa;
	ans += ((ans < 0) ? m : 0);
	return ans;
}

int main() {
	
	int a, b; cin >> a >> b;
	printf("gcd(%d, %d) = %d\n\n", a, b, gcd(a, b));
	
	
	
	Coeff dd = {1, 0};
	Coeff dr = {0, 1};
	int g = linComb(a, b, dd, dr);
	printf("%d = %d(%d) + %d(%d)\n\n", g, a, dr.fa, b, dr.fb);
	
	
	
	int num, m; cin >> num >> m;
	int x = inverseModulo(num, m);
	printf("invMod(%d) = %d (mod %d)\n\n", num, x, m);
	
	
	return 0;
}