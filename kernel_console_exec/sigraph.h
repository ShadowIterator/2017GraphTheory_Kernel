#ifndef SIGRAPH_H
#define SIGRAPH_H

#include "siglobal.h"
#define mp(a,b) make_pair(a,b)

namespace SI
{
	using std::priority_queue;
	using std::pair;
	using std::vector;
	template<class EdgeInfo>
	class Edge
	{
	public:
		EdgeInfo* pdata;
		Edge* next;
		int start;
		int end;
		Edge() :pdata(NULL), next(NULL), end(0)
		{

		}
		Edge(Edge* tnext, int tstart, int tend, const EdgeInfo& tdata) :next(tnext), start(tstart), end(tend)
		{
			pdata = new EdgeInfo(tdata);
		}
	};

	template<class T>
	class Greater
	{
	public:
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};

	template<class EdgeInfo,class VertexInfo>
	class SIGraph
	{
		typedef Edge<EdgeInfo> edge;
		typedef VertexInfo vertex;
		typedef pair<int, int> pii;
	//private:
	public:
		static const int INF = 1 << 29;

		int n, m;
		Edge<EdgeInfo>** Elast;
		VertexInfo** V;
	public:
		SIGraph(int tn = 0) :n(tn), m(0), Elast(NULL), V(NULL)
		{
			if (!n) return;
			Elast = new edge*[n];
			std::memset(Elast, 0, n * sizeof(edge*));
			V = new VertexInfo* [n];
			std::memset(V, 0, n * sizeof(vertex*));
		}
		void delList(edge* edgeListNode)
		{
			if (edgeListNode == NULL) return;
			delList(edgeListNode->next);
			delete edgeListNode;
		}
		void clear()
		{
			for (int i = 0; i < n; ++i)
			{
				delList(Elast[i]);
				Elast[i] = NULL;
			}
		}
		void appendSize(int nn)
		{
			edge** nlast = new edge*[nn];
			std::memcpy(nlast, Elast, n * sizeof(edge*));
			std::memset(nlast + n, 0, (nn - n) * sizeof(edge*));
			delete[] Elast;
			Elast = nlast;
			vertex** nV = new vertex*[nn];
			memcpy(nV, V, n * sizeof(vertex*));
			memset(nV + n, 0, (nn - n) * sizeof(vertex*));
			delete[] V;
			V = nV;
			n = nn;
		}
		void addPath(int u, int v, const EdgeInfo& w)
		{
			edge* ne = new edge(Elast[u], u, v, w);
			Elast[u] = ne;
		}
		void delPath(int u, int v)
		{
	//		if (n == 0)return;
			edge* pp = NULL;
			edge* np = NULL;
			for (np = Elast[u]; np && np->end != v; np = np->next) pp = np;
			if (np == NULL) return;
			if (pp == NULL) Elast[u] = np->next;
			else pp->next = np->next;
			delete np;
		}
		//No out_of_range test
		void dijkstra(int u, int* dist, SIGraph* pgraph = NULL)
		{
			static priority_queue<pii,vector<pii>,Greater<pii> > q;
			int v, w;
			int pu = u;
			edge** prev = new edge* [n];
			while (!q.empty()) q.pop();
			for (int i = 0; i < n; ++i) dist[i] = INF;
			dist[u] = 0;
			q.push(std::make_pair(0, u));
	//		int tu, tw;
			for (int i = 1; i < n; ++i)
			{
				while (dist[q.top().second] != q.top().first)
					q.pop();
				u = q.top().second;
				q.pop();
				for (edge* p = Elast[u]; p != NULL; p = p->next)
					if (dist[v = p->end] > (w = (dist[u] + p->pdata->length())))
					{
						q.push(std::make_pair((dist[v] = w), v));
						prev[v] = p;
					}
			}
			if (pgraph != NULL)
			{
				pgraph->clear();
				for (u = 0; u < n; ++u)
					if (u^pu)
						pgraph->addPath(prev[u]->start, u, *(prev[u]->pdata));
			}
		}
	};
	
}

#endif // !SIGRAPH_H
