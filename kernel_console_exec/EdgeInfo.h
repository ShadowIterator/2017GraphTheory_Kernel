#ifndef EDGEINFO_H
#define EDGEINFO_H

#include "siglobal.h"

namespace SI
{
	class EdgeInfo
	{
	public:
		int w;
		EdgeInfo(int tw = 0);
		int length();
	};
}
#endif // !EDGEINFO_H
