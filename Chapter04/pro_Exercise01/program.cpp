/*--Yêu cầu
* cần quản lý các thông tin 
	DienThoai(MaDienThoai (int), TenDienThoai (string), DonViTinh (string), DonGia (float), SoLuong (int))
	Dùng hashTable để lưu trữ data điện thoại
	- Dùng phương pháp băm kép
	  + Hk1()--> phương pháp chi
	  + HK2()--> M-2(k%(M-2)
	_ key là Số điện thoại
	-1. Tạo cấu trúc bảng băm
	-2. Nhập danh sách data.
	-3. Xóa điện thoại ra khỏi hashTable 
*/

#include <iostream>
#include <string>

using namespace std;
//Tạo cấu trúc lưu thông tin điện thoại
typedef struct phone {
	int Id ;
	string Name;
	string Unit;
	float Price;
	int quantity;
}PHONE;
//Phương thức nhập điện thoại
PHONE InputPhoneInfor(int index)
{
	PHONE phone;
	cout << "Enter phone " << index << ": ";

	cout << "Enter phone ID: ";
	cin >> phone.Id;
	cin.ignore();
	cout << "Enter phone name: ";
	getline(cin, phone.Name);
	cout << "Enter phone unit: ";
	getline(cin, phone.Unit);

	cout << "Enter phone price: ";
	cin >> phone.Price;
	cout << "Enter phone quantity: ";
	cin >> phone.quantity;

	return phone;
}
//In Thông tin của điện thoại
void PrintPhoneInfor(PHONE phone) {
	cout << "ID: " << phone.Id<<endl;
	cout << "Name: " << phone.Name << endl;
	cout << "Unit: " << phone.Unit << endl;
	cout << "Price: " << phone.Price << endl;
	cout << "Quantity: " << phone.quantity << endl;
	cout << "Total: " << phone.quantity*phone.Price << endl;
}

//Tạo cấu trúc hashTable
#define MAX 100
typedef struct hashtable {
	PHONE data[MAX];
	int Count;
}HASHTABLE;
//phương thức khởi tạo hashtable
void InitHashTable(HASHTABLE& hashTable) {
	for (int i = 0; i < MAX; i++)
	{
		hashTable.data[i].Id = -1;
	}
	hashTable.Count = 0;
}
int HK1(int value, int size) {
	return value % size;
}
int HK2(int value, int size) {
	return size - 2 - (value % (size - 2));
}
//1,2,3, a, b, c
void Push(HASHTABLE& hashTable, PHONE value, int size) {
	int j = HK1(value.Id, size);
	int i = HK2(j, size);
	while (hashTable.data[i].Id!=-1 && hashTable.Count<size)
	{
		i = ((++i) * i) % size;//can bac hai
	}
	if (hashTable.Count < size)
	{
		hashTable.data[i] = value;
		hashTable.Count++;
	}
	else {
		cout << "HashTable full";
	}
}
void CreatehashTablePhone(HASHTABLE& hashTable, int size)
{
	int index = 0;
	while (true)
	{
		char option;
		PHONE phone = InputPhoneInfor(index++);
		Push(hashTable, phone, size);
		cout << "Co muon tiep tuc nhap (y/n):";
		cin >> option;
		if (option == 'n')
			break;
	}
}
void DeletePhoneByID(HASHTABLE& hashTable, int size) {
	int value;
	cout << "Nhap id Can xoa: "; cin >> value;

	int j = HK1(value, size);
	int i = HK2(j, size);
	while (hashTable.data[i].Id != -1 && hashTable.data[i].Id!=value)
	{
		i = ((++i) * i) % size;//can bac hai
	}
	if (hashTable.data[i].Id==-1)
	{
		cout << "khong co gia tri can xoa";
	}
	else {
		hashTable.data[i].Id = -1;
		hashTable.Count--;
	}
}

void PrintHashTable(HASHTABLE hashTable)
{
	for (int i = 0; i < MAX; i++)
	{
		if (hashTable.data[i].Id >= 0)
			PrintPhoneInfor(hashTable.data[i]);
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
		number++;
	}
	return number;
}
void main()
{
	int number = 20;
	int size = SoNguyenToCanTim(number);

	HASHTABLE hashTable;
	InitHashTable(hashTable);
	CreatehashTablePhone(hashTable, size);
	PrintHashTable(hashTable);

	DeletePhoneByID(hashTable, size);
	PrintHashTable(hashTable);
	system("pause");
}