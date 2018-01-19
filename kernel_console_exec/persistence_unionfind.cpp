#include "persistence_unionfind.h"

namespace SI
{
	Persistence_UnionFind::Persistence_UnionFind(int tn, int tq) :fath(tn, tq), rank(tn, tq)
	{
		int *temp = new int[tn];
		for (int i = 0; i < tn; ++i)
			temp[i] = i;
		fath.init(temp, tn);
		for (int i = 0; i < tn; ++i)
			temp[i] = 1;
		rank.init(temp, tn);
	}

	void Persistence_UnionFind::resize(int tn, int tq)
	{
		fath.destroy();
		fath.allocBuffer(tn, tq);
		rank.destroy();
		rank.allocBuffer(tn, tq);
	}

	int Persistence_UnionFind::getfath(int x, int u)
	{
		int fa;
		while ((fa = fath.at(x, u)) != u) u = fa;
		return fa;
	}

	void Persistence_UnionFind::merge(int u, int v)
	{
		int lastm = fath.sizeq() - 1;
		u = getfath(lastm, u);
		v = getfath(lastm, v);
		if (!(u^v))
		{
			fath.nopmodify();
			rank.nopmodify();
			return;
		}
		int rku = rank.at(lastm, u);
		int rkv = rank.at(lastm, v);
		if (rku >= rkv)
		{
			fath.modify(v, u);
			if (!(rku^rkv))
				rank.modify(u, rku + 1);
			else rank.nopmodify();
		}
		else
		{
			fath.modify(u, v);
			rank.nopmodify();
		}
	}

	void Persistence_UnionFind::resume(int k)
	{
		fath.resume(k);
		rank.resume(k);
	}

	Persistence_UnionFind::~Persistence_UnionFind()
	{

	}
}