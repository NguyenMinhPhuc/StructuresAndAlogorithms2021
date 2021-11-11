//Phần thực hành về bảng băm.

#include "iostream"
#include "string"
#include <iomanip>

using namespace std;

int menu()
{
	//system("cls");
	cout << endl;
	cout << setfill(' ');
	cout << setw(55) << "-------- MENU -------" << endl;

	cout << setw(55) << "| 1. Nhap day so       |" << endl;
	cout << setw(55) << "| 2. In day so         |" << endl;
	cout << setw(55) << "| 3. Exit              |" << endl;
	cout << setw(55) << "------------------------" << endl;
	int option;
	cout << "Select function: ";
	cin >> option;
	return option;

}
#define MAX 1001

//Tao cau truc bang bam
typedef struct bangBam {
	int data[MAX];
	int soPhanTu;
}HASHTABLE;
//Khoi tao bang bam
void InitHashtable(HASHTABLE& hashTable)
{
	for (int key = 0; key < MAX; key++)
	{
		hashTable.data[key] = -1;
		hashTable.soPhanTu = 0;
	}
}
//ham bam 1
int HK(int value, int size)
{
	return value % size;
}
//Dua gia tri vao bang bam
void Push(HASHTABLE& _hashTable, int value, int size)
{
	int key = HK(value,size);
	//Kiem tra de bam lai
	while (_hashTable.data[key]!=-1&&_hashTable.soPhanTu<size)
	{
		//cong thuc bam lai
		key = ((++key) * key) % size;
	}
	//khong can bam lai
	if (_hashTable.soPhanTu < size)
	{
		_hashTable.data[key] = value;
		_hashTable.soPhanTu++;
	}
	else {
		cout << "Bang bam day";
	}
}
int Searching(HASHTABLE _hashTable, int value, int size)
{
	int key = HK(value, size);
	//Kiem tra de bam lai
	while (_hashTable.data[key] != -1 && _hashTable.data[key] != value)
	{
		//cong thuc bam lai
		key = ((++key) * key) % size;
	}
	//khong can bam lai
	if (_hashTable.data[key]==-1)
	{
		return -1;
	}
	else {
		return key;
	}
}
void DeleteValue(HASHTABLE &_hashTable, int size)
{
	int value;
	cout << "Nhap gia tri can xoa: "; cin >> value;
	int key = Searching(_hashTable, value, size);
	if (key != -1)
	{
		_hashTable.data[key] = -1;
		_hashTable.soPhanTu--;
	}
	else {
		cout << "khong co gia tri can xoa";
	}

}
void NhapDaySoNguyenDuong(HASHTABLE& _hashTable, int size)
{
	int value;
	do
	{
		cout << "Nhap phan tu thu " << _hashTable.soPhanTu + 1<<": ";
		cin >> value;
		if (value != -1)
			Push(_hashTable, value, size);
	} while (value!=-1);
}

void PrintValue(HASHTABLE _hashTable)
{
	for (int i = 0; i < MAX; i++)
	{
		if (_hashTable.data[i] != -1)
		{
			cout << _hashTable.data[i] << " ";
		}
	}
}

bool LaSoNguyenTo(int number)
{
	if (number <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}
int SoNguyenToCanTim(int number)
{
	while (LaSoNguyenTo(number) == false)
	{
		number--;
	}
	return number;
}
void main()
{
	HASHTABLE _hashTable;
	InitHashtable(_hashTable);
	int n = 12;//N<MAX
	while (true)
	{

		int option;
		option = menu();
		
		switch (option)
		{
		case 1:
			cout << setfill('-');
			cout << setw(55) << "-" << endl;
			cout << "Nhap gia tri cho BB" << endl;
			//dừng màn hình cho tới khi nhấp phím bất kỳ

			NhapDaySoNguyenDuong(_hashTable, SoNguyenToCanTim(n));
			PrintValue(_hashTable);
			break;
		case 2:
			cout << setfill('-');
			cout << setw(55) << "-" << endl;
			cout << "In day so nguyen: ";
			//dừng màn hình cho tới khi nhấp phím bất kỳ
			PrintValue(_hashTable);
			system("pause");
			break;
		default:
			return;
		}
	}	
	system("pause");
}