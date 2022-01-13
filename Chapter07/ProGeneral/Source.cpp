//#include <iostream>
//using namespace std;
//
//int a[10], n, stop, _count;
//
//void Init() {
//	stop = 0;
//	cout << "input n: ";
//	cin >> n;
//	_count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = 0;
//	}
//}
////void General()
////{
////	int i = n - 1;
////	while (i >= 0 && a[i] == 1)
////	{
////		i--;
////	}
////	if (i < 0)
////	{
////		stop = 1;
////	}
////	else {
////		a[i] = 1;
////		for (int j = i + 1; j < n; j++)
////		{
////			a[j] = 0;
////		}
////	}
////}
//
//void OutPut() {
//	int dem = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == 1)
//			dem++;
//	}
//	if (dem >= 3) {
//	_count++;
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	}
//
//}
//void Try(int i)
//{
//	for (int v = 0; v <= 1; v++)//Thu tap kha nang
//	{
//		a[i] = v;
//		if (i == n - 1)
//		{
//			OutPut();
//		}
//		else {
//			Try(i + 1);
//		}
//	}
//}
//
////
////void LietKe()
////{
////	Init();
////	while (stop == 0)
////	{
////		//_count++;
////		OutPut();
////		General();
////	}
////}
//void main() {
//	cout << "input n: ";
//	cin >> n;
//	_count = 0;
//	Try(0);
//	cout << "\n So Luong: " << _count;
//	system("pause");
//}