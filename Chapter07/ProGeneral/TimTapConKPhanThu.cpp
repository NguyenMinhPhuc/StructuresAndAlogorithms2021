#include <iostream>

using namespace std;

int n, k, _count, a[100], stop;
void Init()
{
	int i;
	_count = 0;
	cout << "enter n: ";
	cin >> n;
	cout << " Enter k: ";
	cin >> k;

	stop = 0;
	a[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		a[i] = i;
	}
}

void OutPut()
{
	_count++;
	cout << "Tap con thu " << _count << ": \t";
	cout << "{";
	for (int i = 1; i <= k; i++)
	{
		if (i == k) {
			cout << a[i];
		}
		else {
			cout << a[i] << ", ";
		}
	}
	cout << "}" << endl;
}
void General()
{
	int i;
	i = k;
	while (i > 0 && a[i] == n - k + i)
	{
		i--;
	}
	if (i > 0) {
		a[i] = a[i] + 1;
		for (int j = i + 1; j <= k; j++)
		{
			a[j] = a[j - 1] + 1;
		}
	}
	else {
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
void main()
{
	LietKe();
	cout << endl;
	system("pause");
}