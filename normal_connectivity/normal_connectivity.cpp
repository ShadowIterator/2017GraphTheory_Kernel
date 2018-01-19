#include<iostream>	
#include<algorithm>
#include<cstdlib>

using namespace std;

const int MAXN = 1000;
const int MAXM = 5000;
const int MAXQ = 1000;

int fath[MAXN + 5];
int st[MAXM + 5];
int ed[MAXM + 5];
int ww[MAXM + 5];
int rk[MAXM + 5];

inline bool cmp_rk(int i, int j)
{
	return ww[i] > ww[j];
}

inline bool cmp_greater(int a, int b)
{
	return a > b;
}

int getfath(int u)
{
	if (u != fath[u]) fath[u] = getfath(fath[u]);
	return fath[u];
}

void merge(int u, int v)
{
	u = getfath(u);
	v = getfath(v);
	if (!(u^v)) return;
	fath[u] = v;
}

int main()
{
	int n, m, q;
	int u, v, w;
	int k;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> st[i] >> ed[i] >> ww[i];
	for (int i = 1; i <= m; ++i) rk[i] = i;
	sort(rk + 1, rk + 1 + m, cmp_rk);

	for (cin >> q; q; --q)
	{
		cin >> u >> v >> w;
		for (int i = 0; i <= n; ++i) fath[i] = i;
		for (int i = 1; i <= m; ++i)
		{
			if (ww[rk[i]] < w) break;
			merge(st[rk[i]], ed[rk[i]]);
		}
		cout << (getfath(u) == getfath(v)) << endl;
	}
	return 0;
}
/*
4 4
0 1 5
1 2 7
1 3 2
3 0 3
10
0 1 2
0 1 5
0 1 6
1 3 2
1 3 3
1 3 4
1 2 30
1 2 3
0 2 6

*/