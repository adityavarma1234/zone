#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility> 
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MOD = 1000000007;
const int MAX = 1 << 8;
const int MAXT = 1000;
const Int MAXN = 1000000000LL;
const int TESTNUM = 7;

void open(int test_num)
{
	char buf[256];
	sprintf(buf, "C:\\Users\\Віталій\\Desktop\\witua\\Cook-off October\\PPNUM\\%d.in", test_num);
	freopen(buf, "r", stdin);
	sprintf(buf, "C:\\Users\\Віталій\\Desktop\\witua\\Cook-off October\\PPNUM\\%d.out", test_num);
	freopen(buf, "wb", stdout);
}

void Check(Int l, Int r)
{
	if (l < 1 || l > MAXN)
		throw - 1;
	if (r < 1 || r > MAXN)
		throw - 1;
	if (l > r)
		throw - 1;
}

void Solve()
{
	// Read L and R
	Int l, r;
	cin >> l >> r;
	Check(l, r);
	Int a = 1;
	Int b = 9;
	Int res = 0;
	// Iterate through all possible sizes of integers in range [L..R]
	FOR(i, 0, 10)
	{
		// Find lower and upper bound
		Int ll = max(l, a);
		Int rr = min(b, r);
		if (ll <= rr)
		{
			// Calculate the result (as the sum of arithmetic progression)
			Int sum = (ll + rr) * (rr - ll + 1) / 2;
			res += Int(i + 1) * (sum % MOD);
			res %= MOD;
		}
		a = a * 10;
		b = b * 10 + 9;
	}
	// Output the result
	cout << res << endl;
}

int main()
{


#ifndef ONLINE_JUDGE
	FOR(test, 0, TESTNUM)
	{
		open(test);
		int T;
		cin >> T;
		FOR(i, 0, T)
		{
			Solve();
		}
	}
#endif

#ifdef ONLINE_JUDGE
	int T;
	cin >> T;
	FOR(i, 0, T)
	{
		Solve();
	}
#endif

	return 0;
}