//#include "iostream"
//
//using namespace std;
///// <summary>
///// Hàm kiểm tra số nguyên number có phải là số nguyên tố hay không
///// </summary>
///// <param name="number">Số nguyên dương</param>
///// <returns></returns>
//bool LaSoNguyenTo(int number)
//{
//	if (number <= 1)
//	{
//		return false;
//	}
//	for (int i = 2; i <= sqrt(number); i++)
//	{
//		if (number % i == 0)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//void NhapMang(int a[],int &i)
//{
//	i = 0;
//    do
//    {
//		cout << "Nhap A[" << i << "]: ";
//		cin >> a[i];
//		if (a[i] == 0)
//			break;
//		i++;
//    } while (true);
//}
///// <summary>
///// Hàm tính tổng các số nguyên tố
///// </summary>
///// <param name="a">mảng a</param>
///// <param name="n">số phần tử của mảng a</param>
///// <returns></returns>
//int TinhTongSoNguyenTo(int a[],int n)
//{
//	int tong = 0;
//	for(int i=0;i<n;i++){
//		if (LaSoNguyenTo(a[i]))
//		{
//			tong += a[i];
//		}
//	}
//	return tong;
//}
//void main()
//{
//	int a[10];
//	int n = 0;
//	NhapMang(a, n);
//	cout << "Tổng các snt trong mang: " << TinhTongSoNguyenTo(a, n);
//
//	system("pause");
//}