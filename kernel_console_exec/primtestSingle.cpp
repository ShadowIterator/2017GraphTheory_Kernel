//
//#ifndef SIGLOBAL_H
//#define SIGLOBAL_H
//
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <map>
//#include <set>
//#include <cstdlib>
//#include <iostream>
//#include <algorithm>
//
//namespace SI
//{
//	template<class T>
//	T Min(const T& a, const T& b)
//	{
//		return a < b ? a : b;
//	}
//
//	template<class T>
//	T Max(const T& a, const T& b)
//	{
//		return a > b ? a : b;
//	}
//}
//
//#endif // !SIGLOBAL_H
//
//#ifndef SIGRAPH_H
//#define SIGRAPH_H
//
//#define mp(a,b) make_pair(a,b)
//
//namespace SI
//{
//	using std::priority_queue;
//	using std::pair;
//	using std::vector;
//	template<class EdgeInfo>
//	class Edge
//	{
//	public:
//		EdgeInfo* pdata;
//		Edge* next;
//		int start;
//		int end;
//		Edge() :pdata(NULL), next(NULL), end(0)
//		{
//
//		}
//		Edge(Edge* tnext, int tstart, int tend, const EdgeInfo& tdata) :next(tnext), start(tstart), end(tend)
//		{
//			pdata = new EdgeInfo(tdata);
//		}
//	};
//
//	template<class T>
//	class Greater
//	{
//	public:
//		bool operator()(const T& a, const T& b)
//		{
//			return a > b;
//		}
//	};
//
//	template<class EdgeInfo, class VertexInfo>
//	class SIGraph
//	{
//		typedef Edge<EdgeInfo> edge;
//		typedef VertexInfo vertex;
//		typedef pair<int, int> pii;
//		private:
//	public:
//		static const int INF = 1 << 29;
//
//		int n, m;
//		Edge<EdgeInfo>** Elast;
//		VertexInfo** V;
//	public:
//		SIGraph(int tn = 0) :n(tn), m(0), Elast(NULL), V(NULL)
//		{
//			if (!n) return;
//			_allocBuffer();
//		}
//		void _allocBuffer()
//		{
//			if (Elast == NULL) Elast = new edge*[n];
//			std::memset(Elast, 0, n * sizeof(edge*));
//			if (V == NULL) V = new VertexInfo*[n];
//			std::memset(V, 0, n * sizeof(vertex*));
//		}
//		void delList(edge* edgeListNode)
//		{
//			if (edgeListNode == NULL) return;
//			delList(edgeListNode->next);
//			delete edgeListNode;
//		}
//		void clear()
//		{
//			for (int i = 0; i < n; ++i)
//			{
//				delList(Elast[i]);
//				Elast[i] = NULL;
//				delete V[i];
//				V[i] = NULL;
//			}
//		}
//		void destroy()
//		{
//			for (int i = 0; i < n; ++i)
//				delList(Elast[i]);
//			delete[] Elast;
//			for (int i = 0; i < n; ++i)
//				delete V[i];
//			delete[] V;
//			Elast = V = NULL;
//			n = m = 0;
//		}
//		void appendSize(int nn)
//		{
//			edge** nlast = new edge*[nn];
//			std::memcpy(nlast, Elast, n * sizeof(edge*));
//			std::memset(nlast + n, 0, (nn - n) * sizeof(edge*));
//			delete[] Elast;
//			Elast = nlast;
//			vertex** nV = new vertex*[nn];
//			memcpy(nV, V, n * sizeof(vertex*));
//			memset(nV + n, 0, (nn - n) * sizeof(vertex*));
//			delete[] V;
//			V = nV;
//			n = nn;
//		}
//		void addPath(int u, int v, const EdgeInfo& w)
//		{
//			edge* ne = new edge(Elast[u], u, v, w);
//			Elast[u] = ne;
//		}
//		void delPath(int u, int v)
//		{
//					if (n == 0)return;
//			edge* pp = NULL;
//			edge* np = NULL;
//			for (np = Elast[u]; np && np->end != v; np = np->next) pp = np;
//			if (np == NULL) return;
//			if (pp == NULL) Elast[u] = np->next;
//			else pp->next = np->next;
//			delete np;
//		}
//		//No out_of_range test
//		void dijkstra(int u, int* dist, SIGraph* pgraph = NULL)
//		{
//			static priority_queue<pii, vector<pii>, Greater<pii> > q;
//			int v, w;
//			int pu = u;
//			edge** prev = new edge*[n];
//			while (!q.empty()) q.pop();
//			for (int i = 0; i < n; ++i) dist[i] = INF;
//			dist[u] = 0;
//			q.push(std::make_pair(0, u));
//					int tu, tw;
//			for (int i = 1; i < n; ++i)
//			{
//				while (dist[q.top().second] != q.top().first)
//					q.pop();
//				u = q.top().second;
//				q.pop();
//				for (edge* p = Elast[u]; p != NULL; p = p->next)
//					if (dist[v = p->end] >(w = (dist[u] + p->pdata->length())))
//					{
//						q.push(std::make_pair((dist[v] = w), v));
//						prev[v] = p;
//					}
//			}
//			if (pgraph != NULL)
//			{
//				pgraph->clear();
//				for (u = 0; u < n; ++u)
//					if (u^pu)
//						pgraph->addPath(prev[u]->start, u, *(prev[u]->pdata));
//			}
//		}
//
//		int dijkstraStep(int stp, int u, int* dist, edge* selEdge = NULL)
//		{
//			static priority_queue<pii, vector<pii>, Greater<pii> > q;
//			static edge** prev = NULL;//new edge*[n];
//			int v, w, rtn;
//			static int pu;
//			if (stp == 0)
//			{
//				if (prev != NULL)
//				{
//					for (int i = 0; i < n; ++i)
//						delList(prev[i]);
//					delete[] prev;
//				}
//				prev = new edge*[n];
//				while (!q.empty()) q.pop();
//				for (int i = 0; i < n; ++i) dist[i] = INF;
//				dist[pu = u] = 0;
//				q.push(std::make_pair(0, u));
//			}
//
//			while (dist[q.top().second] != q.top().first)
//				q.pop();
//			u = q.top().second;
//			if (selEdge != NULL && (pu^u)) selEdge = prev[u];
//			rtn = dist[u];
//			q.pop();
//			for (edge* p = Elast[u]; p != NULL; p = p->next)
//				if (dist[v = p->end] >(w = (dist[u] + p->pdata->length())))
//				{
//					q.push(std::make_pair((dist[v] = w), v));
//					prev[v] = p;
//				}
//			return rtn;
//		}
//
//		int prim(int u, SIGraph* pgraph = NULL)
//		{
//			static priority_queue<pii, vector<pii>, Greater<pii> > q;
//			int v, w;
//			int pu = u;
//			int rtn = 0;
//			int* dist = new int[n];
//			edge** prev = new edge*[n];
//			while (!q.empty()) q.pop();
//			for (int i = 0; i < n; ++i) dist[i] = INF;
//			dist[u] = 0;
//			q.push(std::make_pair(0, u));
//			for (int i = 0; i < n; ++i)
//			{
//				while (dist[q.top().second] != q.top().first)
//					q.pop();
//				u = q.top().second;
//				rtn += q.top().first;
//				q.pop();
//				for (edge* p = Elast[u]; p != NULL; p = p->next)
//					if (dist[v = p->end] >(w = p->pdata->length()) && (u^v))
//					{
//						q.push(std::make_pair((dist[v] = w), v));
//						prev[v] = p;
//					}
//			}
//			/*	while (dist[q.top().second] != q.top().first)
//			q.pop();
//			rtn += q.top().first;
//			*/	if (pgraph != NULL)
//			{
//				pgraph->clear();
//				for (u = 0; u < n; ++u)
//					if (u^pu)
//						pgraph->addPath(prev[u]->start, u, *(prev[u]->pdata));
//			}
//			return rtn;
//		}
//
//		void betweennessCenterality(int* c)
//		{
//			int** d;
//			d = new int*[n];
//			for (int i = 0; i < n; ++i)
//				d[i] = new int[n];
//			for (int i = 0; i < n; ++i)
//				for (int j = 0; j < n; ++j) d[i][j] = INF;
//			for (int i = 0; i < n; ++i) d[i][i] = 0;
//			for (int u = 0; u < n; ++u)
//				for (edge* p = Elast[u]; p != NULL; p = p->next)
//					d[u][p->end] = p->pdata->length();
//			for (int k = 0; k < n; ++k)
//				for (int i = 0; i < n; ++i)
//					for (int j = 0; j < n; ++j)
//						d[i][j] = Min(d[i][j], d[i][k] + d[k][j]);
//			for (int i = 0; i < n; ++i)
//				for (int k = 0; k < n; ++k)
//					for (int j = 0; j < n; ++j)
//						c[k] += !(d[i][j] ^ (d[i][k] + d[k][j]));
//			for (int i = 0; i < n; ++i)
//				delete d[i];
//			delete d;
//		}
//	};
//
//}
//
//#endif // !SIGRAPH_H
//
//
//using namespace std;
//
//using SI::Edge;
//using SI::SIGraph;
//const int MAXN = 10000;
//class EdgeInfo
//{
//public:
//	int w;
//	EdgeInfo(int tw) :w(tw)
//	{
//
//	}
//	int length()
//	{
//		return w;
//	}
//
//};
//int n, m;
//int u, v, w;
//SIGraph<EdgeInfo, int>* pG = NULL;
//int dist[MAXN];
//int main()
//{
//	int ans;
//	cin >> n;
//	while (n)
//	{
//		if (pG != NULL) delete pG;
//		pG = new SIGraph<EdgeInfo, int>(n);
//		cin >> m;
//		for (; m; --m)
//		{
//			cin >> u >> v >> w;
//			--u;
//			--v;
//			pG->addPath(u, v, w);
//			pG->addPath(v, u, w);
//		}
//		ans = pG->prim(0);
//		cout << ans << endl;
//		cin >> n;
//	}
//	return 0;
//}