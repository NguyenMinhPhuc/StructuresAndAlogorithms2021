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
//void CreateList(LIST& list){
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
//	while (p!=NULL)
//	{
//		//XuLydata
//		cout << p->data<<", ";
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
//void RemoveLast(LIST& dl)
//{
//	NODE* p;
//	if (dl.tail != NULL) {
//		p = dl.tail;//1
//		dl.tail = dl.tail->pre;//2
//
//		if (dl.tail == NULL)
//		{
//			dl.head = NULL;//danh sach rong
//		}
//		else {
//			dl.head->next = NULL;//3
//		}delete p;
//	}
//}
//void RemoveFirst(LIST& dl)
//{
//	NODE* p;
//	if (dl.head != NULL) {
//		p = dl.head;
//		dl.head = dl.head->next;
//		dl.head->pre = NULL;
//
//		delete p;
//
//		if (dl.head == NULL)
//		{
//			dl.tail = NULL;
//		}
//	}
//}
//void RemoveAfterQ(LIST& dl, NODE* q)
//{
//	NODE* p;
//	if (q != NULL) {
//		p = q->next;
//		if (p != NULL) {
//			q->next = p->next;
//			if (p == dl.tail)
//				dl.tail = q;
//			else {
//				p->next->pre = q;
//			}
//			delete p;
//		}
//	}
//}
//void XoaNodeCoViTriK(LIST& list)
//{
//	int k;
//	cout << "Nhap vi tri k:"; cin >> k;
//	NODE* p = SearchingValue(list, k);
//	if (p == list.head) {
//		RemoveFirst(list);
//	}
//	else if (p == list.tail)
//	{
//		RemoveLast(list);
//	}
//	else {
//		RemoveAfterQ(list, p->pre);
//	}
//}
//void main(){
//	LIST list;
//	InitList(list);
//
//	CreateList(list);
//	PrintList(list);
//
//	XoaNodeCoViTriK(list);
//	PrintList(list);
//	system("pause");
//}
