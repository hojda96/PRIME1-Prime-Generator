/*

Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/



#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
void SimpleSieve(vector<int>& Primes, int Limit);
void SegmentedSieve(int Low, int High);


int main()
{
	int t; //test cases
	int m, n; //m and n (1 <= m <= n <= 1000000000, n-m<=100000)
	cin >> t;


	for (int i = 0; i < t; i++) {
		cin >> m;
		cin >> n;
		SegmentedSieve(m, n);
	}

}

void SimpleSieve( vector<int> &Primes,int Limit)
{
	vector<bool> isPrime(Limit+1,true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i < sqrt(Limit); i++) {
		if (isPrime[i])
		{
			for (int j=i*i; j <= Limit; j+=i)
			{
				isPrime[j] = false;
			}
			
		}
	}

	for (int i = 2; i < isPrime.size(); i++) {
		
		if (isPrime[i]) {
			Primes.push_back(i);
		}
	}
	
}

void SegmentedSieve(int Low, int High)
{
	if (Low < 2) Low = 2;
	vector<int> primes;
	SimpleSieve(primes, sqrt(High));

	vector<bool> Range(High - Low + 1, true);


	for (int i = 0; i < primes.size(); i++) {

		int firstMultiple = (Low / primes[i]) * primes[i]; // int division
		if (firstMultiple < Low)  firstMultiple += primes[i]; 

		firstMultiple = max(firstMultiple, primes[i] * primes[i]);
		

		for (int j = firstMultiple; j <= High; j += primes[i]) {
			Range[j - Low] = false;
		
		}

	}
	for (int i=0;i<Range.size();i++)
	{
		
		if (Range[i]) cout << Low+i << '\n';
	}

}