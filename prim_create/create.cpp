#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MAXN = 1000;
const int MAXM = 20000;
const int MAXW = 20000;
const int MAXT = 10;
int n, m;

int u, v, w;

int T;

inline int getrand()
{
	return (rand() << 16) + rand();
}
int main()
{
	srand((unsigned)time(NULL));
	for (T = getrand() % MAXT; T; --T)
	{
		cout << (n = getrand() % MAXN + 1) << " ";
		cout << (m = (n + getrand() % MAXM)) << endl;
		for (int i = 1; i < n; ++i)
		{
			u = getrand() % i;
			w = getrand() % MAXW;
			cout << u + 1 << " " << i + 1 << " " << w << endl;
		}
		for (int i = n; i <= m; ++i)
		{
			u = getrand() % n + 1;
			v = getrand() % n + 1;
			w = getrand() % MAXW + 1;
			cout << u << " " << v << " " << w << endl;
		}
	}
	cout << endl << 0 << endl;
	return 0;
}