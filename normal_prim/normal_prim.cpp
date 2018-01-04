#include<iostream>
using namespace std;

const int MAXN = 1005;
const int INF = 1 << 27;
int dist[MAXN];
bool used[MAXN];
int ans;
int mapp[MAXN][MAXN];
int n, m;
int u, v, w;

inline int Min(int a, int b)
{
	return a < b ? a : b;
}

inline void prim()
{
	ans = 0;
	u = 0;
	for (int i = 0; i < n; ++i) used[i] = false;
	for (int i = 0; i <= n; ++i)
		dist[i] = INF;
	dist[0] = 0;
	int minid;
	for (int i = 0; i < n; ++i)
	{
		minid = n;
		for (u = 0; u < n; ++u)
			if ((!used[u]) && dist[u] < dist[minid])
				minid = u;
		u = minid;
		used[u] = true;
		ans += dist[u];
		for (v = 0; v < n; ++v)
			if (dist[v] > mapp[u][v])
				dist[v] = mapp[u][v];
	}
}

int main()
{
	cin >> n;
	while (n)
	{
		cin >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				mapp[i][j] = INF;
		for (; m; --m)
		{
			cin >> u >> v >> w;
			--u; --v;
			mapp[u][v] = Min(mapp[u][v], w);
			mapp[v][u] = Min(mapp[v][u], w);
		}
		prim();
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}