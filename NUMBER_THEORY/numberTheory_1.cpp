#include <bits/stdc++.h>
using namespace std;

// =================================================================================
// =================================================================================
/*
RUNNING TIME = O(sqrt(N)) ...
To check whether a given number is PRIME or not
It also finds counts the number of divisors (inclu. 1 and N itself)
*/
bool checkPrime(int N)
{
	int count = 0;
	for(int i=1; i*i<=N; i++)
	{
		if(N % i == 0)
		{
			count++;
			if(i*i != N) count ++;
		}
	}
	
	bool iP = (count == 2) ? true : false;
	return iP;
}
// =================================================================================
// =================================================================================
/*
RUNNING TIME = O(N.log(logN)) ...
sieve to store a boolean value corresponding to each numbers:
[0] 		= false
[1] 		= false
[prime] 	= true
[composite] = false
*/
vector< bool > sieve(int N)
{
	vector< bool > isPrime(N+1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	
	for(int i=2; i*i<=N; i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i; j<=N; j+=i)isPrime[j] = false;
		}
	}
	
	return isPrime;
}

// =================================================================================
// =================================================================================
/*
RUNNIGN TIME = O(N.log(logN)) ...
Modified sieve to store the smallest prime divisor corresponding to each composite no.
[0] 		= -1
[1] 		= -1
[prime] 	= 0
[composite] = smallest prime divisor
*/
vector< int > sieve_modified(int N)
{
	vector< int > spd(N+1, 0);
	spd[0] = -1;
	spd[1] = -1;
	
	for(int i=2; i*i<=N; i++)
	{
		if(spd[i] == 0)
		{
			for(int j=i*i; j<=N; j+=i)
			{
				if(spd[j] == 0) spd[j] = i;
			}
		}
	}
	return spd;
}

// =================================================================================
// =================================================================================
/*
RUNNING TIME = O(sqrt(N)) ...
To list the divisors of a composite number including 1 and N 
*/
vector< int > getDivisors(int N)
{
	vector< int > divisors;
	for(int i=1; i*i<=N; i++)
	{
		if(N % i == 0)
		{
			divisors.push_back(i);
			int j = N / i;
			if(j!=i) divisors.push_back(j); 
		}
	}
	return divisors;
}

// =================================================================================
// =================================================================================
/*
RUNNING TIME = O(sqrt(N)) ...
To find the prime factorization array of a number N
*/
vector< int > primeFactorization(int N)
{
	vector< int > pfz;
	for(int i=2; i*i<=N; i++)
	{
		while(N % i == 0)
		{
			pfz.push_back(i);
			N /= i;
		}
	}
	if(N != 1) pfz.push_back(N); // required when the pf is greater than the SQRT
	return pfz;
}

// =================================================================================
// =================================================================================
/*
RUNNING TIME = O(logN)
To find the prime factorization array of a number N (with precalculated minPrime sieve)
*/
vector< int > primeFactorization_preSieve(int N, vector< int >minPrimes)
{
	vector< int > pfz;
	while(N > 1)
	{
		int d = (minPrimes[N] == 0) ? N : minPrimes[N];
		
		pfz.push_back(d);
		N /= d;
	}
	return pfz;
}

// =================================================================================
// =================================================================================
// =================================================================================
// =================================================================================

int main()
{
	int N;
	cin >> N;
	
	cout << "\nisPrime...\n";
	vector< bool > isPrime = sieve(N);
	for(int i=0; i<=N; i++) cout << i << "\t" << isPrime[i] << "\n";
	
	cout << "\nSmallest prime divisor...\n";
	vector< int > spd = sieve_modified(N);
	for(int i=0; i<=N; i++) cout << i << "\t" << spd[i] << "\n";
	
	cout << "\nDivisors of N...\n";
	vector< int > divs = getDivisors(N);
	sort(divs.begin(), divs.end());
	for(int i=0; i<divs.size(); i++) cout << divs[i] << "\n";
	
	cout << "\nPrime Factorization of N...\n";
	vector< int > pfz = primeFactorization(N);
	for(int i=0; i<pfz.size(); i++) cout << pfz[i] << "\n";
	
	cout << "\nPrime Factorization (pre sieve) of N...\n";
	vector< int > pfz2 = primeFactorization_preSieve(N, spd);
	for(int i=0; i<pfz2.size(); i++) cout << pfz2[i] << "\n";
	
	
	return 0;
}

