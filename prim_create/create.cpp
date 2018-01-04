#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MAXN = 1000;
const int MAXM = 10000;
const int MAXW = 20000;
int n, m;

int u, v, w;

int main()
{
	srand((unsigned)time(NULL));
	cout << (n = rand() % MAXN + 1) << " ";
	cout << (m = (n + rand() % MAXM)) << endl;
	for (int i = 1; i < n; ++i)
	{
		u = rand() % i;
		w = rand() % MAXW;
		cout << u + 1 << " " << i + 1 << " " << w << endl;
	}
	for (int i = n; i <= m; ++i)
	{
		u = rand() % n + 1;
		v = rand() % n + 1;
		w = rand() % MAXW + 1;
		cout << u << " " << v << " " << w << endl;
	}
	cout << endl << 0 << endl;
	return 0;
}