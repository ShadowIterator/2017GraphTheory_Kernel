#include"siglobal.h"
#include"sigraph.h"

using namespace std;

using SI::Edge;
using SI::SIGraph;
const int MAXN = 10000;
class EdgeInfo
{
public:
	int w;
	EdgeInfo(int tw) :w(tw)
	{

	}
	int length()
	{
		return w;
	}

};
int n, m;
int u, v, w;
SIGraph<EdgeInfo, int>* pG;
int dist[MAXN];
int main()
{
	cin >> n >> m;
	pG = new SIGraph<EdgeInfo, int>(n);
	for (; m; --m)
	{
		cin >> u >> v >> w;
		pG->addPath(u - 1, v - 1, EdgeInfo(w));
	}
	cin >> u >> v;
	--u;
	//pG->dijkstra(u - 1, dist);
	for (int i = 0; i < n; ++i)
		pG->dijkstraStep(i, u, dist);
	cout << dist[v - 1] << endl;
	return 0;
}