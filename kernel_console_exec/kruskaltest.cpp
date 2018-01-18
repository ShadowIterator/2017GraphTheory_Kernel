#include"siglobal.h"
#include"sigraph.h"
#include"EdgeInfo.h"
#include"VertexInfo.h"

using namespace std;

//using SI::Edge;
using SI::SIGraph;
using SI::EdgeInfo;
using SI::VertexInfo;

const int MAXN = 10000;
int n, m;
int u, v, w;
SIGraph<EdgeInfo, VertexInfo>* pG = NULL;
int dist[MAXN];
int main()
{
	EdgeInfo ei;
	int ans;
	cin >> n;
	while (n)
	{
		if (pG != NULL) delete pG;
		pG = new SIGraph<EdgeInfo, VertexInfo>(n);
		cin >> m;
		for (; m; --m)
		{
			cin >> ei;
			--ei.u;
			--ei.v;
			pG->addPath(ei);
			ei.u ^= ei.v ^= ei.u ^= ei.v;
			pG->addPath(ei);
		}
		//ans=pG->prim(0);
		/*for (int i = 0; i < n; ++i)
			ans = pG->primStep(i, 0);
		*/
		ans = 0;
		for (int i = 0; i + 1 < n; ++i)
		{
			pG->KruskalStep(i, &ei);
			ans += ei.w;
		}
		cout << ans << endl;
		cin >> n;
	}
	return 0;
}