#include <bits/stdc++.h>
using namespace std;


// To return a boolean vector containing the flags to identify whether i is prime
// where, 0 <= i <= N (vector contains N+1 elements, 0 to N (both inclusive))
vector<bool> getPrimes(long N)
{
	vector <bool> isPrime(N+1, true);
	isPrime[0] = false; isPrime[1] = false;
	
	for(long i=2; (i*i)<N; i++)
	{
		if(isPrime[i])
		{
			for(long j=i*i; j<=N; j+=i)
				isPrime[j] = false;
		}
	}
	
	return isPrime;
}
//==============================================================

// To find the exponiation of x raised to the power y
long long fastExpo(long long x, long long y)
{
	long long res = (x==0 || x==1) ? x : 1;
	while(y != 0)
	{
		if(y & 1) res *= x;
		x *= x;
		y = y >> 1;
	}
	return res;
}
//==============================================================

// To find the exponiation of x raised to the power y
// response to be given in MOD m
long long fastExpo_modular(long long x, long long y, long long m)
{
	long long res = (x==0 || x==1) ? x : 1;
	while(y != 0)
	{
		if(y & 1) res = ((res % m) * (x % m))%m;
		x = ((x % m) * (x % m))%m;
		y = y >> 1;
	}
	return res;
}
//==============================================================



//==============================================================
//==============================================================
//==============================================================
//==============================================================
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	// long N;
	// cin >> N;
// 	
	// vector <bool> vec = getPrimes(N);
	// for(long i=0; i<=N; i++)
	// {
		// if(vec[i]) cout << i << "\n";
	// }
	
	// long long x, y, m;
	// cin >> x >> y >> m;
// 	
	// cout << fastExpo(x,y);
	// cout << fastExpo_modular(x,y,m);
}