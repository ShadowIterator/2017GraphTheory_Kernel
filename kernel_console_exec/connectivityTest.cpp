#include"siglobal.h"
#include"persistence_unionfind.h"
#include"sigraph.h"
#include"EdgeInfo.h"
#include"VertexInfo.h"

using namespace std;

using PUF=SI::Persistence_UnionFind;

const int MAXN = 1005;
const int MAXM = 10000;
const int MAXQ = 1005;
PUF uf(MAXN, MAXQ);

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

//template<class T>
//inline int binSearch_upper(T* a, int l, int r, bool(*cmp)(const T&, const T&))
//{
//	int mid;
//	while (l <= r)
//	{
//		mid = (l + r) >> 1;
//		if(!cmp(a[]))
//	}
//}
using SI::EdgeInfo;
using SI::SIGraph;
using SI::EdgeInfo;
using SI::VertexInfo;
SIGraph<EdgeInfo, VertexInfo>* pG = NULL;
int main()
{
	int n, m, q;
	int u, v, w;
	int k;
	EdgeInfo ei;
	cin >> n >> m;
	pG = new SIGraph<EdgeInfo, VertexInfo>(n);
	for (int i = 1; i <= m; ++i)
	{
		//cin >> st[i] >> ed[i] >> ww[i];
		cin >> ei;
		pG->addPath(ei);
	}
	/*for (int i = 1; i <= m; ++i) rk[i] = i;
	sort(rk + 1, rk + 1 + m, cmp_rk);
	for (int i = 1; i <= m; ++i)
		uf.merge(st[rk[i]], ed[rk[i]]);
	sort(ww + 1, ww + 1 + m, cmp_greater);
	ww[m + 1] = 1 << 29;*/
	pG->connectivityInit();
	for (cin >> q; q; --q)
	{
		cin >> u >> v >> w;
		// k = binSearch(ww, 1, m + 1);
		/*k = upper_bound(ww + 1, ww + 1 + m, w, cmp_greater) - ww - 1;
		cout << (uf.getfath(k, u) == uf.getfath(k, v)) << endl;*/
		cout << pG->connectivityQuery(u, v, w) << endl;
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

10 3
10 1 30
3 1 28
10 1 1
10
9 7 26
5 10 23
9 6 37
6 3 41
1 9 46
8 8 5
7 6 17
5 6 19
6 4 34
9 4 8
*/