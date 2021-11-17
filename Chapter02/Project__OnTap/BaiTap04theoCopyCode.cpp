//#include "iostream"
//
//using namespace std;
//
////Xay dung cau truc danh sach;
//typedef int dataType;
//typedef struct node {
//	dataType data;
//	node* next;
//	node* pre;
//}NODE;
//
//typedef struct list {
//	NODE* head;
//	NODE* tail;
//}LIST;
//
////tao node
//NODE* GetNode(dataType value)
//{
//	NODE* p = new NODE;
//	if (p == NULL)
//		exit(1);
//	p->data = value;
//	p->next = NULL;
//	p->pre = NULL;
//	return p;
//}
//
//void InitList(LIST& list)
//{
//	list.head = list.tail = NULL;
//}
//
//void AddFirst(LIST& list, NODE* new__Node)
//{
//	if (list.head == NULL)//Rong
//	{
//		new__Node->next = list.head;
//		list.head = new__Node;
//	}
//	else//Khac rong
//	{
//		new__Node->next = list.head;
//		list.head->pre = new__Node;
//		list.head = new__Node;
//	}
//}
//void InsertList(LIST& list, float x)
//{
//	NODE* p = GetNode(x);
//	AddFirst(list, p);
//}
//void CreateList(LIST& list) {
//	dataType data;
//	while (true)
//	{
//		cout << "Nhap data: "; cin >> data;
//		if (data < 0) {
//			break;
//		}
//		InsertList(list, data);
//	}
//}
//void PrintList(LIST list) {
//	NODE* p = list.head;
//	while (p != NULL)
//	{
//		//XuLydata
//		cout << p->data << ", ";
//		p = p->next;
//	}
//}
//
//NODE* SearchingValue(LIST dl, int k)
//{
//	NODE* p = dl.head;
//	int index = 1;
//	while (p != NULL) {
//
//		if (index == k)
//			return p;
//		p = p->next;
//		index++;
//	}
//	return NULL;
//}
//void AddBeforQ(LIST& dl, NODE* q, NODE* newNode)
//{
//	if (q != NULL)
//	{
//		NODE* p = q->pre;
//		newNode->next = q;//1
//		newNode->pre = p;//2
//		q->pre = newNode;	//4
//		if (q != dl.head)
//		{
//			p->next = newNode;//3
//		}
//		else {
//			dl.head = newNode;
//		}
//
//	}
//	else {
//		AddFirst(dl, newNode);
//	}
//}
//void ChenGiaTriXVaoViTriK(LIST& list) {
//	int x, k;
//	cout << "nhap x:"; cin >> x;
//	cout << "nhap k:"; cin >> k;
//
//	NODE* p = GetNode(x);
//	NODE* q = SearchingValue(list, k);
//	if (q != NULL) {
//		AddBeforQ(list, q, p);
//	}
//	else {
//		cout << "khong co vi tri can tim";
//	}
//	
//}
//void main() {
//	LIST list;
//	InitList(list);
//
//	CreateList(list);
//	PrintList(list);
//
//	ChenGiaTriXVaoViTriK(list);
//	PrintList(list);
//	system("pause");
//}
//--------------------------Khanh------------------------
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>  
//
//using namespace std;
//
//
//typedef struct dnode
//{
//	int data;
//	dnode* pre;
//	dnode* next;
//} DNODE;
//
//
//typedef struct dlist
//{
//	DNODE* head;
//	DNODE* tail;
//} DLIST;
//
//
//void InitDlist(DLIST& dlist)
//{
//	dlist.head = dlist.tail = NULL;
//}
//
//
//DNODE* GetDNode(int data)
//{
//	DNODE* new_node = new DNODE;
//
//	if (new_node == NULL)
//	{
//		exit(0);
//	}
//
//	new_node->data = data;
//	new_node->pre = NULL;
//	new_node->next = NULL;
//
//	return new_node;
//}
//
//
//void PrintDlist(DLIST dlist)
//{
//	DNODE* p;
//
//	p = dlist.head;
//
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->next;
//	}
//
//	cout << endl;
//
//}
//
//void AddHead(DLIST& dlist, DNODE* new_node)
//{
//	if (dlist.head == NULL)
//	{
//		dlist.head = new_node;
//		dlist.tail = dlist.head;
//	}
//	else
//	{
//		dlist.head->pre = new_node;
//		new_node->next = dlist.head;
//		dlist.head = new_node;
//	}
//}
//
//
//void AddTail(DLIST& dlist, DNODE* new_node)
//{
//	if (dlist.head == NULL)
//	{
//		dlist.head = new_node;
//		dlist.tail = dlist.head;
//	}
//	else
//	{
//		dlist.tail->next = new_node;
//		new_node->pre = dlist.tail;
//		dlist.tail = new_node;
//	}
//}
//
//
//void InsertDlist(DLIST& dlist, int data)
//{
//	DNODE* new_Dnode = GetDNode(data);
//	AddTail(dlist, new_Dnode);
//
//}
//
//void CreateDList(DLIST& dlist, int n)
//{
//	int data;
//	srand(time(0));
//
//	for (int i = 0; i < n; i++) {
//		data = 1 + rand() % (1000 - 0 + 1) + 0;
//		InsertDlist(dlist, data);
//	}
//
//}
//
//
//void InsertXatposK(DLIST& dlist, int n, int x, int k)
//{
//	DNODE* p = dlist.head, * q, * temp;
//	DNODE* new_node = GetDNode(x);
//	int i = 1;
//
//	if (k < 1 || k > n + 1) {
//		cout << "Invalid position!! " << n << endl;
//	}
//	else
//	{
//		temp = GetDNode(x);
//
//		if (k == 1) AddHead(dlist, new_node);
//
//		else
//			if (k == n + 1) AddTail(dlist, new_node);
//
//			else
//			{
//				while (p != NULL && i != k - 1)
//				{
//					i++;
//					p = p->next;
//				}
//
//				q = p->next;
//				temp->next = q;
//				temp->pre = p;
//				p->next = temp;
//				q->pre = temp;
//
//			}
//	}
//}
//
//void Insert(DLIST& dlist, int n) {
//	int x, k;
//	cout << "Data you want to insert: ";
//	cin >> x;
//
//	cout << "At pos: ";
//	cin >> k;
//	if ((k > n + 1) && (k < n + 2)) n++;
//	InsertXatposK(dlist, n, x, k);
//	cout << "\t Your new list: " << endl;
//	PrintDlist(dlist);
//}
//
//
//int main()
//{
//	DLIST list;
//	int n;
//	bool selected = false;
//	string op;
//
//	cout << "Luu y: Danh sach duoc random [0;1000] theo so luong phan tu da nhap." << endl;
//
//	InitDlist(list);
//
//	cout << "Nhap so luong phan tu trong danh sach: ";
//	cin >> n;
//
//	CreateDList(list, n);
//
//	cout << endl << "\t Your list: " << endl;
//	PrintDlist(list);
//
//	Insert(list, n);
//
//
//	while (selected == false)
//	{
//		cout << "Ban co muon them tiep khong? Y/N: ";
//		cin >> op;
//		n++;
//		if (op == "y" || op == "Y") {
//			Insert(list, n);
//		}
//		else
//		{
//			selected = true;
//		}
//	}
//
//	system("pause");
//
//}

//-----------------------------Canh------------------------------
#include<iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* pre;
};
struct List {
	node* head;
	node* tail;
};
List* createList(int x) {
	List* l = new List;
	l->head = new node;
	l->head->data = x;
	l->head->pre = NULL;
	l->head->next = NULL;
	l->tail = l->head;
	return l;
}
List* themvaodau(List* l, int x) {
	node* temp = new node;
	temp->data = x;
	temp->pre = NULL;
	temp->next = l->head;
	l->head->pre = temp;
	l->head = temp;
	return l;
}
List* themvaocuoi(List* l, int x) {
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	temp->pre = l->tail;
	l->tail->next = temp;
	l->tail = temp;
	return l;
}
List* addAt(List* l, int k, int x) {
	node* p = l->head;
	for (int i = 0; i < k - 1; i++) {
		p = p->next;
	}
	node* temp = new node;
	temp->data = x;
	temp->pre = p;
	temp->next = p->next;
	p->next->pre = temp;
	p->next = temp;
	return l;
}
void printList(List* l) {
	node* p = l->head;
	cout << "danh sach sau khi chen: ";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}




int main() {
	int n, x, k;
	cout << "nhap so phan tu cua danh sach lien ket doi: ";
	cin >> n;
	cout << "nhap lan luot tung phan tu: ";
	cin >> x;
	List* l = createList(x);
	for (int i = 1; i < n; i++) {

		cin >> x;
		l = themvaocuoi(l, x);
	} 	cout << "nhap vi tri muon chen phan tu: ";
	cin >> k; cout << "nhap gia tri phan tu muon chen: ";
	cin >> x;
	if (k == 0) {
		l = themvaodau(l, x);
	}
	else if (k == n || k > n) {
		l = themvaocuoi(l, x);
	}
	else {
		l = addAt(l, k, x);
	}

	printList(l);

}