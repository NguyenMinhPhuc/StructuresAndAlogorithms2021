/*Xây dựng cấu trúc liên kết đơn để lưu danh sách số nguyên dương nhập từ bàn phím.
Bước 01: Xây dựng cấu trúc danh sách liên kết đơn.
Bước 02: Khởi tạo danh sách liên kết đơn.
Bước 03: Xây dựng cấu trúc 1 node trong danh sách liên kết đơn. 
Bước 04: Xây dựng hành động cho Single List.
 + Thêm một node vào đầu danh sách.
 + Thêm một node vào cuối danh sách 
 + Viết phương thức insertList (Thêm 1 data vào trong List)
 + Viết phương thức Nhập một danh sách số nguyên và insert vào trong danh sách.
 + Viết phương thức in danh sách ra màn hình
*/
#include "iostream"

using namespace std;
//Cấu trúc node
typedef struct node
{
	int data;
	node* link;
}NODE;
//Câu trúc danh sách
typedef struct list
{
	NODE* first;
	NODE* last;
}LIST;
//phuong thưc Khởi tạo một danh sách rỗng
void InitList(LIST &list)
{
	list.first = NULL;
	list.last = NULL;
}

//Phương thức tạo ra một node Cô đơn
NODE* GetNode(int data)
{
	NODE* p;
	p =(NODE*) malloc(sizeof(NODE));
	//p = new NODE;
	if (p == NULL)
	{
		exit(1);
	}
	p->data = data;
	p->link = NULL;
	return p;
}
void Addfirst(LIST& list, NODE* new_ele)
{
	if (list.first == NULL)
	{
		list.first = new_ele;//1
		list.last = list.first;//2
	}
	else
	{
		new_ele->link = list.first;
		list.first = new_ele;
	}
}
void InsertList(LIST& list, int data)
{
	NODE* p;
	p = GetNode(data);
	if (p != NULL)
	{
		Addfirst(list, p);
	}
}
void CreateList(LIST& list)
{
	InitList(list);
	int data;
	while (true)
	{
		cout << "input data: ";
		cin >> data;
		if (data != -1) {
			InsertList(list, data);
		}
		else { break; }
	}
}
//Duyet danh sach
void PrintList(LIST list)
{
	NODE* p;
	p = list.first;
	while (p!=NULL)
	{
		//xy ly data
		cout << p->data<<" ";
		//tang p sang pt tiep theo
		p = p->link;
	}
}
void main()
{
	LIST list;
	CreateList(list);
	PrintList(list);
	system("pause");
}