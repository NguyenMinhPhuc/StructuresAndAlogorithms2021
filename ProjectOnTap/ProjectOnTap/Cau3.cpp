#include <iostream>
using namespace std;

#define MAX 20

int a[MAX];
int n;

void OutPut()
{
	int dem1 = 0, dem0 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
			dem1++;
		else
		{
			dem0++;
		}
	}
	if (dem1 > dem0)
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
		}
		cout << endl;
	}
}
//dang 1: day nhi phan
//dang 2: Chinh hop n chap k ( khong lap va khong hoan vi
// dang 3: hoan vi n.
//dang 4: chinh hop n chap k (lap) k>n
void Try(int i)
{
	//for (int v =i; v <= n-k+i; v++)
	//for (int v = 1; v <= n; v++)
	for (int v = 0; v < 2; v++)
	{
		//if (c[v] == 0)
		//{
		a[i] = v;
		if (i == n - 1)
		{
			OutPut();
		}
		else {
			/*c[v]=1*/
			Try(i + 1);
			/*c[v]=0*/
		}
		//}
	}
}
void main()
{
	cout << " nhap n: "; cin >> n;
	Try(0);
	system("pause");
}