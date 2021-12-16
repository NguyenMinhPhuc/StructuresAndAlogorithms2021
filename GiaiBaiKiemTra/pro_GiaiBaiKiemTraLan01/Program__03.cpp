//Một hội đồng tuyển sinh quản lý các thí sinh dự thi theo các thông tin sau :
//-SoBD : chuỗi gồm 5 kí tự số
//- Họ tên : chuỗi gồm tối đa 30 kí tự
//- Khu vực ưu tiên : chuỗi “KV1”, “KV2” hoặc “KV3”
//- Điểm thi môn Toán, Lý, Hóa : số thực

#include <iostream>
#include <string>

//#include <sstream>

using namespace std;

typedef struct thiSinh {
	string soBD;
	string hoTen;
	string khuVuc;
	float toan;
	float ly;
	float hoa;
}THISINH;


#define MAX 1001

typedef THISINH dataType;


//Tao cau truc bang bam
typedef struct hashTable {
	dataType data[MAX];
	int soPhanTu;
}HASHTABLE;

int ConvertToInt32(string inputString)
{
	int i=-1;
	if (inputString != "")
	{
		i = stoi(inputString);
	}
	return i;
}
void InitHashtable(HASHTABLE& hashTable)
{
	for (int key = 0; key < MAX; key++)
	{
		hashTable.data[key].soBD = "- 1" ;
		hashTable.soPhanTu = 0;
	}
}
int FuncKey(string value, int size)
{
	return ConvertToInt32(value) % size;
}

void Push(HASHTABLE& _hashTable, dataType value, int size)
{
	int key = FuncKey(value.soBD, size);
	//Kiem tra de bam lai
	while (_hashTable.data[key].soBD == "-1"  && _hashTable.soPhanTu < size)
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
bool KiemTraMaTrung(HASHTABLE _hashTable, string value, int size)
{
	if (_hashTable.soPhanTu != 0){
		int key = FuncKey(value, size);
		int dem = 0;
		//Kiem tra de bam lai
		while (_hashTable.data[key].soBD == "-1" && _hashTable.data[key].soBD != value) {
			//cong thuc bam lai
			key = ((++key) * key) % size;
			dem++;
			if (dem == size)
			{
				break;
			}
		}
		//khong can bam lai
		if (_hashTable.data[key].soBD == "- 1" ) {
			return false;
		}
		else {
			return true;
		}
	}else {
		return false;
	}
}
dataType InputThiSinh(HASHTABLE _hashTable, int size)
{
	dataType thiSinh;
	
		cin.ignore();
		nhaplai:
		cout << "Nhap SoBD: ";
		getline(cin, thiSinh.soBD);
		if (KiemTraMaTrung(_hashTable, thiSinh.soBD, size)) {
			goto nhaplai;
		}
		
	
	cout << "Nhap ho va ten: ";
	getline(cin, thiSinh.hoTen);

	cout << "Nhap Khu vu (KV1, KV2, KV3 ...): ";
	getline(cin, thiSinh.khuVuc);

	cout << "Nhap Toan: ";
	cin >> thiSinh.toan;

	cout << "Nhap Ly: ";
	cin >> thiSinh.ly;

	cout << "Nhap Hoa: ";
	cin >> thiSinh.hoa;

	return thiSinh;
}

void PrintThiSinh(dataType thiSinh) {
	cout << "SBD: " << thiSinh.soBD << " - HoTen: " << thiSinh.hoTen << " - Khu vuc: " << thiSinh.khuVuc << " - Diem(T,L,H):  " << thiSinh.toan << ", " << thiSinh.ly << ", " << thiSinh.hoa << endl;
}
void NhapDayDanhSachThiSinh(HASHTABLE& _hashTable, int size)
{
	dataType value;
	char option;
	do
	{
		cout << "Nhap Thi Sinh thu " << _hashTable.soPhanTu + 1 << ": ";
		value= InputThiSinh(_hashTable,size);

		Push(_hashTable, value, size);

		cout << "Do you want to Continue ... (y/n): "; 
		cin >> option;
		if (option == 'n')
			break;
	} while (true);
}

void PrintValue(HASHTABLE _hashTable)
{
	for (int i = 0; i < MAX; i++)
	{
		if (ConvertToInt32(_hashTable.data[i].soBD) != -1)
		{
			PrintThiSinh(_hashTable.data[i]);
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
void main() {
	int number = 12;
	int size = SoNguyenToCanTim(number);
	HASHTABLE _hashTable;
	InitHashtable(_hashTable);
	NhapDayDanhSachThiSinh(_hashTable, size);

	PrintValue(_hashTable);


	system("pause");
}