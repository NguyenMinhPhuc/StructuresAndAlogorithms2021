#include <iostream>

using namespace std;

int n, k, _count, a[10], stop, c[10];

string nguoi[] = { "Thuy","Phuong","Tu","Nam" ,"Nhan","Thanh" };

string kytu[] = { " ","A","B","C" };

void Swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void Init()
{
	_count = 0;
	cout << "enter n: ";
	cin >> n;

	stop = 0;

	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		c[i] = 0;
	}
}

void OutPut()
{
	_count++;
	int dem = 0;
	/*for (int i = 0; i < 9; i++)
	{
		if ((a[i] == 2 && a[i + 1] == 5) || (a[i] == 5 && a[i + 1] == 2))
		{
			dem++;
		}
	}
	if (dem == 1) {*/
	/*cout << "Tap con thu " << _count << ": \t";*/
	cout << "{";
	for (int i = 0; i < 5; i++)
	{
		if (i == 5 - 1) {
			cout << kytu[a[i]];
			//cout << a[i];
		}
		else {
			cout << kytu[a[i]] << ", ";
			//cout << a[i];
		}
	}
	cout << "}" << endl;
	//}
}
void General()
{
	int i;
	i = n - 1;
	while (a[i] < a[i - 1])
	{
		i--;
	}
	if (i > 0)
	{
		//tim phan tu k trong doan i-->n-1
		int k;
		for (k = n - 1; k >= i; k--)
		{
			if (a[k] > a[i - 1])
				break;
		}
		Swap(a[k], a[i - 1]);
		//dao nguoc day thanh tang dan tu vi tri i
		for (int j = i; j < i + (n - i) / 2; j++)
		{
			Swap(a[j], a[n - 1 - j + i]);
		}
	}
	else
	{
		stop = 1;
	}
}
void LietKe() {
	Init();
	while (stop == 0)
	{
		OutPut();
		General();
	}
}
void Try(int i)
{

	for (int v = 1; v <= n; v++)//Thu tap kha nang
	{
		/*if (c[v - 1] == 0)
		{*/
		a[i] = v;

		if (i == 4)
		{
			OutPut();
		}
		else {
			//c[v - 1] = 1;
			Try(i + 1);
			//c[v - 1] = 0;
		}
		//}
	}
}
void main()
{
	Init();
	Try(0);
	cout << endl;
	system("pause");
}