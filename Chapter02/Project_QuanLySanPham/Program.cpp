//-----//
#include "iostream"
#include "string"
#include "iomanip"
using namespace std;

typedef struct sanpham
{
	int MaSP;
	string TenSP;
	string DVT;
	int GiaBan;
}SANPHAM;

typedef SANPHAM dataType;

dataType InPutSP(int ID)
{
	dataType sp;
	//Phép gán chỉ dùng 1 dấu =
	sp.MaSP = ID;
	cout << "MaSP : " << ID << endl;
	//cout << "MaSP : "; cin >> sp.MaSP;
	cout << "Ten san pham : ";
	cin.ignore();
	getline(cin, sp.TenSP);
	cout << "Don Vi Tinh :";
	getline(cin, sp.DVT);
	cout << "Gia Ban :";
	cin >> sp.GiaBan;
	return sp;
}

void OutPutSP(dataType sp, int row)
{
	if (row == 0)
	{
		cout << setw(5) << left << "MaSp";
		cout << setw(30) << left << "| Ten san pham";
		cout << setw(30) << left << "| Don vi tinh";
		cout << setw(20) << left << "| Gia Ban" << endl;
		cout << setfill('-');
		cout << setw(85) << "-" << endl;
	}
	// reset fill b?ng ký t? ' '
	cout << setfill(' ');
	cout << setw(5) << left << sp.MaSP;
	cout << setw(30) << left << sp.TenSP;
	cout << setw(30) << left << sp.DVT;
	cout << setw(20) << left << sp.GiaBan;
}
//T?o c?u trúc node cho danh sách liên k?t
typedef struct node
{
	dataType data;//Thành ph?n Data
	node* link;//Thành ph?n Link
}NODE;

typedef struct list {
	NODE* first;
	NODE* last;
}LIST;

void InitList(LIST& list)
{
	list.first = list.last = NULL;
}

NODE* GetNode(dataType sp)
{
	NODE* p = new NODE;
	if (p == NULL)
		exit(1);
	p->data = sp;
	p->link = NULL;
	return p;
}

void AddFirst(LIST& list, NODE* newNode)
{
	if (list.first == NULL)
	{
		list.first = newNode;
		list.last = list.first;
	}
	else {
		newNode->link = list.first;
		list.first = newNode;
	}
}

void InsertList(LIST& list, dataType sp)
{
	NODE* p = GetNode(sp);
	AddFirst(list, p);
}
int MaxID(LIST list)
{
	if (list.first == NULL)
		return 1;
	return list.first->data.MaSP + 1;
}
int MaxID01(LIST list)
{
	int maxID = 0;
	NODE* p = list.first;
	while (p != NULL)
	{
		if (p->data.MaSP > maxID)
			maxID = p->data.MaSP;
		p = p->link;
	}
	return maxID + 1;
}
void CreateList(LIST& list)
{
	dataType sp;
	string option;
	do {
		sp = InPutSP(MaxID(list));
		InsertList(list, sp);
		cout << "Ban co muon nhap tiep ? (y/n): " << endl; cin.ignore();
		getline(cin, option);
	} while (option == "y");
}

void PrintSPList(LIST list)
{
	NODE* p = list.first;
	int i = 0;
	while (p != NULL)
	{
		OutPutSP(p->data, i++);
		p = p->link;
	}
}

void SearchingSPBYID(LIST& list)
{
	int ID;
	cout << "nhap MaSP muon tim :"; cin >> ID;
	NODE* p = list.first;
	while (p != NULL)
	{
		if (p->data.MaSP == ID)
		{
			OutPutSP(p->data, 0);
			cout << endl;
		}
		p = p->link;
	}
}



void SearchingSPGIA(LIST& list)
{
	int gia;
	cout << "nhap gia muon tim:"; cin >> gia;
	NODE* p = list.first;
	while (p != NULL)
	{
		if (p->data.GiaBan == gia)
		{
			OutPutSP(p->data, 0);
			cout << endl;

		}
		p = p->link;
	}
}
int menu()
{
	int option = 0;
	cout << "1. Input San Pham" << endl;
	cout << "2. Output San Pham" << endl;
	cout << "3. Searching San pham by MaSP" << endl;
	cout << "4. Searching San pham by Gia" << endl;
	cout << "5. Exit" << endl;
	cout << "Select Function: ";
	cin >> option;
	return option;
}
void main()
{
	int option;
	LIST l;

	InitList(l);
	while (true)
	{
		option = menu();
		switch (option)
		{
		case 1:
			CreateList(l);
			break;
		case 2:
			PrintSPList(l);
			break;
		case 3:
			SearchingSPBYID(l);
			break;
		case 4:
			SearchingSPGIA(l);
			break;
		case 5:
			return;
		}
	}
	system("pause");

}