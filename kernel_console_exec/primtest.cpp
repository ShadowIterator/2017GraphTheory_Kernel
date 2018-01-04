//#include"siglobal.h"
//#include"sigraph.h"
//#include"EdgeInfo.h"
//#include"VertexInfo.h"
//
//using namespace std;
//
//using SI::Edge;
//using SI::SIGraph;
//using SI::EdgeInfo;
//using SI::VertexInfo;
//
//const int MAXN = 10000;
//int n, m;
//int u, v, w;
//SIGraph<EdgeInfo, VertexInfo>* pG = NULL;
//int dist[MAXN];
//int main()
//{
//	int ans;
//	cin >> n;
//	while (n)
//	{
//		if (pG != NULL) delete pG;
//		pG = new SIGraph<EdgeInfo, VertexInfo>(n);
//		cin >> m;
//		for (; m; --m)
//		{
//			cin >> u >> v >> w;
//			--u;
//			--v;
//			pG->addPath(u, v, w);
//			pG->addPath(v, u, w);
//		}
//		ans=pG->prim(0);
//		cout << ans << endl;
//		cin >> n; 
//	}
//	return 0;
//}