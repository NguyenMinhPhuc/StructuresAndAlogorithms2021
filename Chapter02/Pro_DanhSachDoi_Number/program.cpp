#include "iostream"

using namespace std;
//Khai bao cau truc dnode.
typedef struct dnode {
	int data;
	dnode* pre;
	dnode* next;
}DNODE;

typedef DNODE* ptrDnode;

//khai baos cau truc dLIST
typedef struct dlist {
	DNODE* head;
	DNODE* tail;
}DLIST;
//Khoi tao Dlist
void InitDlist(DLIST& dlist)
{
	dlist.head = dlist.tail = NULL;
}

DNODE* GetDnode(int value)
{
	DNODE* newNode = new DNODE;
	if (newNode == NULL)
		exit(1);
	newNode->data = value;
	newNode->pre = NULL;
	newNode->next = NULL;
	return newNode;
}
void AddFirst(DLIST& dl, DNODE* newNode)
{
	if (dl.head == NULL)//Kiểm tra danh sách rỗng.
	{
		dl.head = newNode;
		dl.tail = dl.head;
	}
	//Danh sach khong rong
	else {
		newNode->next = dl.head;//1
		dl.head->pre = newNode;//2
		dl.head = newNode;//3
	}
}

void AddLast(DLIST& dl, DNODE* newNode)
{
	if (dl.head == NULL)//Kiểm tra danh sách rỗng.
	{
		dl.head = newNode;
		dl.tail = dl.head;
	}
	//Danh sach khong rong
	else {
		dl.tail->next = newNode;//1
		newNode->pre = dl.tail;//2
		dl.tail = newNode;//3
	}
}
void AddAfterQ(DLIST& dl, DNODE* q, DNODE* newNode){
	if (q != NULL){
		DNODE* p = q->next;
		newNode->next = p;//1
		newNode->pre = q;//2
		q->next = newNode;//3
		if (q != dl.tail){
			p->pre = newNode;//4
		}
		else {
			dl.tail = newNode;
		}
	}else{
		AddLast(dl, newNode);
	}
}
void AddBeforQ(DLIST& dl, DNODE* q, DNODE* newNode)
{
	if(q!=NULL)
	{ 
		DNODE* p = q->pre;
		newNode->next = q;//1
		newNode->pre = p;//2
		q->pre = newNode;	//4
		if (q != dl.head)
		{
			p->next = newNode;//3
		}
		else {
			dl.head = newNode;
		}

	}
	else {
		AddFirst(dl, newNode);
	}
}
DNODE* SearchingValue(DLIST dl, int x)
{
	DNODE* p = dl.head;
	while (p!=NULL){
		if (p->data == x)
			return p;
		p = p->next;
	}
	return NULL;
}
void InsertAfterValueX(DLIST& dl, int value, int x)
{
	DNODE* q = SearchingValue(dl, x);
	DNODE* newNODE = GetDnode(value);
	AddAfterQ(dl, q, newNODE);

}
void InsertBeforValueX(DLIST& dl, int value, int x)
{
	DNODE* q = SearchingValue(dl, x);
	DNODE* newNODE = GetDnode(value);
	AddBeforQ(dl, q, newNODE);
}
void InsertDlist(DLIST& dl, int value, bool last)
{
	DNODE* p = GetDnode(value);
	if (last == true) {
		AddLast(dl, p);
	}
	else {
		AddFirst(dl, p);
	}
}
void CreateDlist(DLIST& dl,bool last)
{
	int value;
	while (true)
	{
		cout << "Input Value: ";
		cin >> value;
		if (value == -1)
		{
			break;
		}
		InsertDlist(dl, value,last);
	}
}
//in xuoi
void PrintDlist01(DLIST dl) {
	DNODE* p = dl.head;
	while (p!=NULL)
	{
		//Xu ly node
		cout << p->data<<" ";
		p = p->next;
	}
}
//in nguoc
void PrintDlist02(DLIST dl) {
	DNODE* p = dl.tail;
	while (p != NULL)
	{
		//Xu ly node
		cout << p->data << " ";
		p = p->pre;
	}
}

void RemoveFirst(DLIST& dl)
{
	DNODE* p;
	if (dl.head != NULL) {
		p = dl.head;
		dl.head = dl.head->next;
		dl.head->pre = NULL;

		delete p;

		if (dl.head == NULL)
		{
			dl.tail = NULL;
		}
	}
}
int RemoveFirstGetData(DLIST& dl)
{
	DNODE* p;
	int data=-1;
	if (dl.head != NULL) {
		p = dl.head;
		dl.head = dl.head->next;
		dl.head->pre = NULL;
		data = p->data;
		delete p;

		if (dl.head == NULL)
		{
			dl.tail = NULL;
		}
	}
	return data;
}

void RemoveLast(DLIST& dl)
{
	DNODE* p;
	if (dl.tail != NULL) {
		p = dl.tail;
		dl.tail = dl.head->pre;
		dl.head->next = NULL;

		delete p;

		if (dl.tail == NULL)
		{
			dl.head = NULL;
		}
	}
}
void main()
{
	DLIST dl;
	bool last = true;
	InitDlist(dl);
	CreateDlist(dl, last);
	PrintDlist01(dl);
	cout << endl;
	PrintDlist02(dl);
	cout << endl;
	InsertAfterValueX(dl, 10, 9);
	PrintDlist01(dl);
	cout << endl;
	InsertBeforValueX(dl, 10, 9);
	PrintDlist01(dl);
	cout << endl; 
	system("pause");
}