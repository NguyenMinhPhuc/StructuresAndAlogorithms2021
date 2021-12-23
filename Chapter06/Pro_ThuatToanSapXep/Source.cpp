#include <iostream>
using namespace std;

void HoanVi(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//Selection Sort
void SelectionSort(int source[], int n)
{
	int min;//chi muc của phần tử chứa giá trị nhỏ nhất
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i+1; j < n; j++)
		{
			if (source[j] < source[min])
			{
				min = j;
			}
		}
		//hoan vi i va min
		HoanVi(source[i], source[min]);
	}
}
void printArray(int source[],int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << source[i] << " ";
	}
}
//Insert Sort
void InsertSort(int source[], int n)
{
	int pos;
	int x;//Lưu giá trị đang xét
	for (int i=1; i < n; i++)
	{
		x = source[i];
		pos = i - 1;
		while ((pos >= 0) && source[pos] > x)
		{
			source[pos + 1] = source[pos];
			pos--;
		}
		source[pos + 1] = x;
	}
}

void BinaryInsertSort(int source[], int n)
{
	int left, right, mid;
	int x;//Lưu giá trị đang xét
	for (int i = 1; i < n; i++)
	{
		x = source[i];
		left = 1;
		right = i - 1;
		//Vi tri can tim la left
		while (left <=right)
		{
			mid = (left + right) / 2;
			if (x < source[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		//Dich chuyen cac gia tri
		for (int j = i-1; j >=left; j--)
		{
			source[j + 1] = source[j];
		}
		source[left] = x;
	}
}
void InterChangedSort(int source[], int n) {
	for ( int i= 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (source[i] > source[j])
				HoanVi(source[i], source[j]);
		}
	}
}

void BubleSort(int source[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n-1; j >i; j--)
		{
			if (source[j] < source[j-1])
				HoanVi(source[j], source[j-1]);
		}
	}
}
void shift(int source[], int left, int right)
{
	int x, i, j;
	i = left;
	j = 2 * i;
	x = source[i];
	while (j <= right) {
		//kiểm tra số lượng phần tử liên đới.
		//nếu có 1 phần tử liên đới (j=right) chỉ xét j
		//Nếu có 2 phần tử liên đới (j<right)
		if (j < right) {
			if (source[j] < source[j + 1])
				j = j + 1;
		}
		if (source[j] >= x)
		{
			source[i] = source[j];
			i = j;
			j = 2 * i;
			source[i] = x;
		}
		else {
			break;
		}
	}
}
//Chinh heap ban dau
void CreateHeap(int source[], int n){
	int i;
	i = n / 2;
	while (i > 0)
	{
		shift(source, i, n);
		i--;
	}
	/*cout << "\n";
	printArray(source, n);*/
}
void HeapSort(int source[], int n) {
	int right;//phaan tu cuoi cung
	CreateHeap(source, n);
	right = n - 1;
	while (right > 0)
	{
		HoanVi(source[1], source[right]);//hoan vi pt so 1, voi phan tu cuoi cung
		right--;//loai bo phan tu cuoi cung
		shift(source, 1, right);
	}
}
void merge(int source[], int left, int mid, int right)
{
	int i, j, k;
	int c[50];
	i = left;
	j = mid + 1;
	k = left;
	while (i<=mid&&j<=right) {
		if (source[i] < source[j])
		{
			c[k] = source[i];
			k++;
			i++;
		}
		else {
			c[k] = source[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = source[i];
		k++; i++;
	}
	while (j <= right)
	{
		c[k] = source[j];
		k++; j++;
	}
	for (int l =left; l < right; l++)
	{
		source[l] = c[l];
	}
}
void MergeSort(int source[], int left, int right) {
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(source, left , mid);
		MergeSort(source, mid + 1, right);
		

		merge(source, left, mid, right);
	}
}
void main(){
	int source[] = { 1,4,2,6,8,3,9,7,10 };
	int n = 9;

	printArray(source, n);

	/*CreateHeap(source, n);
	cout << "heap: " << endl;
	printArray(source, n);*/
	//SelectionSort(source, n);
	MergeSort(source,0,n-1);
	cout << endl;

	printArray(source, n);
	system("pause");
}