#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MAXN = 1000;
const int MAXM = 2000;
const int MAXW = 500000;
const int MAXQ = 1000;
const int MAXT = 1;
int n, m;

int u, v, w;

int T, q;

inline int getrand()
{
	return (rand() << 16) + rand();
}
int main()
{
	srand((unsigned)time(NULL));
	for (T = getrand() % MAXT + 1; T; --T)
	{
		(n = getrand() % MAXN + 1);
		//n = MAXN;
		(m = (getrand() % MAXM));

		cout << n << " ";
		cout << m << endl;
		//for (int i = 1; i < n; ++i)
		//{
		//	u = getrand() % i;
		//	w = getrand() % MAXW;
		//	cout << u + 1 << " " << i + 1 << " " << w << endl;
		//}
		for (int i = 1; i <= m; ++i)
		{
			u = getrand() % n ;
			v = getrand() % n ;
			w = getrand() % MAXW + 1;
			cout << u << " " << v << " " << w << endl;
		}
		for (cout << (q =  MAXQ) << endl; q; --q)
		{
			u = getrand() % n ;
			v = getrand() % n ;
			w = getrand() % MAXW + 1;
			cout << u << " " << v << " " << w << endl;
		}
	}

	return 0;
}