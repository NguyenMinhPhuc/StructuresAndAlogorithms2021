#include<iostream>

using namespace std;
bool searchingLinear1(int a[], int n,int x)
{
	int i = 0;
	while ((i<n)&&(a[i]!=x))
	{
		i++;
	}
	if (i == n) {
		return false;
	}
	else {
		return true;
	}
}
int searchingLinear2(int a[], int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i]!=x)
	{
		i++;
	}
	if (i == n) {
		return false;
	}
	else {
		return true;
	}
}
int BinarySearch1(int* a, int x, int left, int right)
{
	int mid = (left + right) / 2;

	if (x > a[mid] && left < mid)
		return BinarySearch1(a, x, mid + 1, right);
	else if (x > a[mid] && right > mid) {
		return BinarySearch1(a, x, left, mid - 1);
	}
	else if(x==a[mid]) {
		return mid;
	}
	return -1;
}
int BinarySearch2(int* a, int x, int n)
{
	int mid, left = 0, right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (x > a[mid])
			left = mid + 1;
		else if (x < a[mid]) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
void main() {
	int a[] = { 1,2,3,4,5,6,7,8,9,10,-1};
	int n= 10;
	int x = 4;
	if (searchingLinear1(a, n, x)) {
		cout << "co";
	}
	else {
		cout << "khong";
	}

	if (searchingLinear2(a, n, x)) {
		cout << "co";
	}
	else {
		cout << "khong";
	}
}