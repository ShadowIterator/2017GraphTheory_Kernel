#ifndef SIGLOBAL_H
#define SIGLOBAL_H

#include <cstring>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <thread>

namespace SI
{
	template<class T>
	T Min(const T& a, const T& b)
	{
		return a < b ? a : b;
	}
	
	template<class T>
	T Max(const T& a, const T& b)
	{
		return a > b ? a : b;
	}
}

#endif // !SIGLOBAL_H
