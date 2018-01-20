//#define _CRT_SECURE_NO_WARNINGS
//#include"siglobal.h"
//#include"persistence_unionfind.h"
//#include"sigraph.h"
//#include"EdgeInfo.h"
//#include"VertexInfo.h"
//
//using namespace std;
//
//using PUF = SI::Persistence_UnionFind;
//
//const int MAXN = 1005;
//const int MAXM = 10000;
//const int MAXQ = 1005;
//PUF uf(MAXN, MAXQ);
//
//int st[MAXM + 5];
//int ed[MAXM + 5];
//int ww[MAXM + 5];
//int rk[MAXM + 5];
//
//inline bool cmp_rk(int i, int j)
//{
//	return ww[i] > ww[j];
//}
//
//inline bool cmp_greater(int a, int b)
//{
//	return a > b;
//}
//
////template<class T>
////inline int binSearch_upper(T* a, int l, int r, bool(*cmp)(const T&, const T&))
////{
////	int mid;
////	while (l <= r)
////	{
////		mid = (l + r) >> 1;
////		if(!cmp(a[]))
////	}
////}
//using SI::EdgeInfo;
//using SI::SIGraph;
//using SI::EdgeInfo;
//using SI::VertexInfo;
//SIGraph<EdgeInfo, VertexInfo>* pG = NULL;
//int main()
//{
//	freopen("filmgraph.txt", "r", stdin);
//	freopen("res.out", "w", stdout);
//	int n, m, q;
//	int u, v, w;
//	int k;
//	EdgeInfo ei;
//	cin >> n >> m;
//	pG = new SIGraph<EdgeInfo, VertexInfo>(n);
//	for (int i = 1; i <= m; ++i)
//	{
//		cin >> ei;
//		pG->addPath(ei);
//		ei.u ^= ei.v ^= ei.u ^= ei.v;
//		pG->addPath(ei);
//	}
//	int* c = new int[n];
////	pG->betweennessCentralityImproved(c);
//	//pG->betweennessCentrality(c);
//
//	//pG->closenesscentrality(c);
//	for (int i = 0; i < n; ++i)
//		cout << c[i] << endl;
//	return 0;
//}
///*
//5 4
//0 1 5
//1 2 7
//1 3 2
//3 0 2
//10
//0 1 2
//
//*/