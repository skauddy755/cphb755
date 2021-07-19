#include <bits/stdc++.h>
#define ll long long
using namespace std;

// =================================================================================
// =================================================================================
/*
RUNNING TIME O(log(N))...
*/
ll bin_expo(int x, int y)
{
	ll a = x;
	ll ans = (y % 2 == 0) ? 1 : x;
	y = y >> 1;
	while(y != 0)
	{
		int d = y & 1;
		a = a*a;
		if(d) ans = ans * a;
		y = y >> 1;
	}
	return ans;
}

// =================================================================================
// =================================================================================
/*
RUNNING TIME O(log(N))...
*/
ll bin_mod_expo(int x, int y, int m)
{
	ll a = x;
	ll ans = (y % 2 == 0) ? 1 : x;
	y = y >> 1;
	while(y != 0)
	{
		int d = y & 1;
		a = (a*a) % m;
		if(d) ans = (ans * a) % m;
		y = y >> 1;
	}
	return ans;
}

// =================================================================================
// =================================================================================
/*
RUNNING TIME O(log(N))...
*/
ll gcd(int A, int B) // assuming: A->dividend, B->divisor
{
	if(B == 0) return A;
	gcd(B, A%B);
}

int gcd_xy(int A, int B, vector< pair< int,int > > xy, int i)
{
	if(B == 0) return A;
	
	int q = A/B;
	if(i==0)
	{
		xy[i].first = 1;
		xy[i].second = -q;
	}
	else if(i==1)
	{
		xy[i].first = -q * xy[0].first;
		xy[i].second = 1 - q * xy[0].second;
	}
	else
	{
		xy[i].first = xy[i-2].first - q * xy[i-2].first;
		xy[i].second = xy[i-2].second - q * xy[i-2].second;
	}
	gcd_xy(B, A%B, xy, i+1);
}

// =================================================================================
// =================================================================================
// =================================================================================
// =================================================================================
int main()
{
	cout << "\nBinary exponentiation:\n";
	int x = 3, y = 23;
	cout << bin_expo(x, y);
	
	cout << "\nBinary Modular Exponentiation:\n";
	int m = 14;
	cout << bin_mod_expo(x, y, m);
	
	cout << "\nGCD of 2 numbers:\n";
	int A = 12, B = 48;
	cout << gcd(B, A);
	
	cout << "\nGCD_XY of 2 numbers:\n";
	vector< pair< int,int > > xy(B);
	cout << gcd_xy(B, A, xy, 0) << " ---\n";
	for(int i=0; i<B; i++) cout << xy[i].first << " , " << xy[i].second << "\n";
}