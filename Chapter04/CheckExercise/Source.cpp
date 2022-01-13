#include<iostream>
#include<string>
using namespace std;
int menu()
{
	int option = 0;
	cout << "1. Nhap thong tin dien thoai" << endl;
	cout << "2.	In thong tin dien thoai" << endl;
	cout << "Select Function: ";
	cin >> option;
	return option;
}
typedef struct dienthoai {
	int mdt;
	//chỉnh lại cho phép nhập theo kiểu string
	string tendt;
	string donvi;
	float dongia;
	int soluong;
}DIENTHOAI;

DIENTHOAI Nhap_01_Mat_Hang(int i) {
	DIENTHOAI _DienThoai;
	cout << "Nhap thong tin dien thoai thu " << i << ": \n";
	cout << "Ma dien thoai : ";
	cin >> _DienThoai.mdt;
	//Nhập giá trị kiểu string
	cin.ignore();
	cout << "Ten Dien Thoai : ";//fflush(stdin);
	getline(cin,_DienThoai.tendt);
	cout << "don vi : ";
	getline(cin, _DienThoai.donvi);
	
	cout << "Don Gia : ";
	cin >> _DienThoai.dongia;
	cout << "So Luong : ";
	cin >> _DienThoai.soluong;
	return _DienThoai;
}
void Prin_01_DienThoai(DIENTHOAI& dienthoai) {
	cout << "Ma Dien Thoai : " << dienthoai.mdt << endl;
	cout << "Ten Dien Thoai : " << dienthoai.tendt << endl;
	cout << "Don Vi : " << dienthoai.donvi << endl;
	cout << "Don Gia : " << dienthoai.dongia << endl;
	cout << "So Luong : " << dienthoai.soluong << endl;
}
#define MAX 101   
int HK1(int value, int size) {
	return(value % size);
}
int HK2(int value, int size) {
	return size - 2 - (value % (size - 2));
}
typedef struct bangbam {
	DIENTHOAI data[MAX];
	int sopt;
}BB;
void Init(BB& b, int size) {
	for (int i = 0; i < size; i++) {
		b.data[i].mdt = -1;
	}
	b.sopt=0;
}
void Push(BB& b, DIENTHOAI value, int size) {
	int i = HK1(value.mdt, size);
	int j = HK2(value.mdt, size);
	while (b.data[i].mdt != -1 && b.sopt < size)
	{
		i = (i + j) % size;
	}if (b.sopt < size) {
		b.data[i] = value;
		b.sopt++;
	}
	else {
		cout << "bang bam day : ";
	}
}
//Viết thêm hàm nhập danh sách sản phẩm
void Input(BB& b,int size)
{
	int i = 0;
	char option;
	while (true)
	{
		Push(b, Nhap_01_Mat_Hang(i++), size);
		cout << "ban co muon nhap tiep (y/n): ";
		cin >> option;
		if (option == 'n')
			break;
	}
}
//Viết thêm hàm in danh sách sản phẩm
void Print(BB& b)
{
	for (int i = 0; i < MAX; i++)
	{
		if (b.data[i].mdt > 0)
		{
			Prin_01_DienThoai(b.data[i]);
		}
	}
}
int main() {
	//Khai báo bảng băm
	BB b;
	Init(b,9);

	int option;
	DIENTHOAI dienthoai;
	int i = 0;
	i++;
	while (true)
	{
		option = menu();
		switch (option)
		{
		case 1:
			Input(b,9);
			break;
		case 2:
			Print(b);
			break;
		}
	}
	system("pause");
}