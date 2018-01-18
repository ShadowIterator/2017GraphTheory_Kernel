#if defined(_WIN32)
#define DllExport   __declspec(dllexport)
#else
#define DllExport
#endif

//#include
//#include "json.hpp"
//#include "GerwGraph.h"
//#include "Utility.h"
//#include <fstream>
//#include <iostream>
//#include "ConnectedComponent.h"
//using json = nlohmann::json;
//using namespace std;
#include"siglobal.h"
#include"sigraph.h"
#include"EdgeInfo.h"
#include"VertexInfo.h"

using SI::EdgeInfo;
using SI::VertexInfo;
using Edge = SI::EdgeNode<EdgeInfo>;
using Graph = SI::SIGraph<EdgeInfo, VertexInfo>;

extern "C" {
	DllExport Graph* createGrahp_n(int n)
	{
		Graph* pG = new Graph(n);
		return pG;
	}
	DllExport void destroyGraph(Graph* pG)
	{
		if (pG != NULL) delete pG;
	}
	DllExport EdgeInfo* createEdgeInfo(int u = 0, int v = 0, int w = 0)
	{
		EdgeInfo* pE = new EdgeInfo(u, v, w);
		return pE;
	}
	DllExport void destroyEdgeInfo(EdgeInfo* pE)
	{
		if(pE!=NULL) delete pE;
	}
	DllExport Graph* createGraph_s(const char* s)
	{
		Graph* pG;
		std::ifstream fin;
		fin.open(s);
		int n, m, u, v;
		EdgeInfo ei;
		fin >> n;
		pG = new Graph(n);
		for (int i = 0; i < n; ++i)
			fin >> pG->V[i];
		for (fin >> m; m; --m)
		{
			fin >> ei;
			pG->addPath(ei);
		}
		return pG;
	}
	DllExport void dijkstraStep(Graph* pG, int stp, int u, int* dist, EdgeInfo* pE)
	{
		pG->dijkstraStep(stp, u, dist, pE);
	}
	DllExport void dijkstra(Graph* pG, int u, int* dist, Graph* pSG = NULL)
	{
		pG->dijkstra(u, dist, pSG);
	}

}