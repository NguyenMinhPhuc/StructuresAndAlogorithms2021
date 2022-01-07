////Định nghĩa và xây dựng DSLK đơn lưu trữ dãy gồm N ≤ 1000 số nguyên dương được nhập từ bàn phím.Lập trình đảo ngược thứ tự các phần tử của danh sách.Xuất DSLK đảo ngược ra màn hình.
//#include <iostream>
//using namespace std;
//
//typedef struct node {
//	int data;
//	node* link;
//}NODE;
//typedef struct list {
//	NODE* first;
//	NODE* last;
//}LIST;
//
//void Init(LIST& list)
//{
//	list.first = list.last = NULL;
//}
//NODE* GetNode(int data)
//{
//	NODE* p = new NODE;
//	if (p == NULL) {
//		exit(1);
//	}
//	else {
//		p->data = data;
//		p->link = NULL;
//	}
//}
//void AddFirst(LIST& list, NODE* newelement)
//{
//	if (list.first == NULL)
//	{
//		list.first = newelement;
//		list.last = list.first;
//	}
//	else {
//		newelement->link = list.first;
//		list.first = newelement;
//	}
//}
//void InsertList(LIST& list, int data)
//{
//	NODE* p = GetNode(data);
//	if (p != NULL)
//	{
//		AddFirst(list, p);
//	}
//}
//void CreateList(LIST& list) {
//	Init(list);
//	int data;
//	while (true)
//	{
//		cout << "Input data: "; cin >> data;
//		if (data != -1)
//		{
//			InsertList(list, data);
//		}
//		else {
//			break;
//		}
//	}
//}
//
//void PrintList(LIST list)
//{
//	NODE* p = list.first;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->link;
//	}
//}
//LIST DaoNguocDay(LIST listnguon) {
//	LIST listResult;
//	Init(listResult);
//	NODE* p = listnguon.first;
//
//	while (p != NULL)
//	{
//		InsertList(listResult, p->data);
//		p = p->link;
//	}
//
//	return listResult;
//}
//void main()
//{
//	LIST list;
//	LIST list2;
//	CreateList(list);
//
//	PrintList(list);
//	cout << endl;
//	list2 = DaoNguocDay(list);
//	PrintList(list2);
//	system("pause");
//}