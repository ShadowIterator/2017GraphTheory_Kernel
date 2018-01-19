//#include"siglobal.h"
//#include"persistencearry.h"
//
//using namespace std;
//
//using SI::PerArray;
//
//PerArray<int> pa(10, 5);
//
//int main()
//{
//	pa.init(NULL, 0);
//	pa.modify(2, 2);
//	pa.modify(3, 4);
//	pa.modify(2, 3);
//	cout << pa.at(1, 1) << endl
//		<< pa.at(1, 2) << endl
//		<< pa.at(2, 1) << endl
//		<< pa.at(3, 2) << endl
//		<< pa.at(3, 3) << endl
//		<< pa.at(1, 3) << endl
//		<< pa.at(2, 3) << endl
//		<< pa.at(2, 2) << endl;
//	
//	pa.resume(2);
//	cout << pa.at(2, 2) << endl;
//	pa.modify(2, 4);
//	//cout << pa.at(2, 2);
//	cout << pa.at(3, 2) << endl;
//
//}