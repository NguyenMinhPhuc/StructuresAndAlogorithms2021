///*Xây dựng cấu trúc liên kết đơn để lưu danh sách số nguyên dương nhập từ bàn phím.
//Bước 01: Xây dựng cấu trúc danh sách liên kết đơn.
//Bước 02: Khởi tạo danh sách liên kết đơn.
//Bước 03: Xây dựng cấu trúc 1 node trong danh sách liên kết đơn. 
//Bước 04: Xây dựng hành động cho Single List.
// + Thêm một node vào đầu danh sách.
// + Thêm một node vào cuối danh sách 
// + Viết phương thức insertList (Thêm 1 data vào trong List)
// + Viết phương thức Nhập một danh sách số nguyên và insert vào trong danh sách.
// + Viết phương thức in danh sách ra màn hình
//*/
//#include "iostream"
//#include "string"
//#include "math.h"
//#include <iomanip>
//
//using namespace std;
////Cấu trúc node
//typedef struct node
//{
//	int data;
//	node* link;
//}NODE;
////Câu trúc danh sách
//typedef struct list
//{
//	NODE* first;
//	NODE* last;
//}LIST;
////phuong thưc Khởi tạo một danh sách rỗng
//void InitList(LIST &list)
//{
//	list.first = NULL;
//	list.last = NULL;
//}
//
////Phương thức tạo ra một node Cô đơn
//NODE* GetNode(int data)
//{
//	NODE* p;
//	p =(NODE*) malloc(sizeof(NODE));
//	//p = new NODE;
//	if (p == NULL)
//	{
//		exit(1);
//	}
//	p->data = data;
//	p->link = NULL;
//	return p;
//}
////Phương thức thực hiện thao tác thêm một node vào đầu danh sách.
////Phương thức này có 2 tham số: 1 là danh sách kiểu LIST, 2 là một con trỏ NODE nắm giữ 1 NODE (node muốn thêm vào.
////Có 2 trường học cần xử lý khi thêm 1 node vào đầu danh sách: 
//// TH1: Thêm vào danh sách rỗng (first = NULL
//void Addfirst(LIST& list, NODE* new_ele)
//{
//	if (list.first == NULL)
//	{
//		list.first = new_ele;//1
//		list.last = list.first;//2
//	}
//	else
//	{
//		new_ele->link = list.first;
//		list.first = new_ele;
//	}
//}
//void AddLast(LIST& list, NODE* new_ele)
//{
//	if (list.first == NULL)
//	{
//		list.first = new_ele;//1
//		list.last = list.first;//2
//	}
//	else
//	{
//		list.last->link = new_ele;//3
//		list.last = new_ele;
//	}
//
//}
//void AddAfterNodeQ(LIST& list, NODE* new_ele, NODE* q)
//{
//	if (q != NULL && new_ele != NULL)
//	{
//		new_ele->link = q->link;
//		q->link = new_ele;
//		if (q == list.last)
//		{
//			list.last = new_ele;
//		}
//	}
//}
//NODE* Searching(LIST& list, int x) {
//	NODE* p;
//	p = list.first;
//	while (p!=NULL&&p->data!=x)
//	{
//		p = p->link;
//	}
//	return p;
//}
//void AddXAfterValue(LIST& list, int value, int x)
//{
//	NODE* new_ele = GetNode(x);
//	NODE* q = Searching(list, value);
//	if (q != NULL && new_ele != NULL)
//	{
//		AddAfterNodeQ(list, new_ele, q);
//	}
//	else {
//		cout << "ko them duoc";
//	}
//}
////Phương thức thực hiện tác vụ thêm một giá trị data (sô nguyên) vào trong danh sách hiện có.
////Thao tác này được thực hiện như sau:
////Từ giá trị data được truyền từ tham số. Ta gọi hàm GetNode(data) để tạo một cấu trúc NODE cho danh sách liên kết đơn.
////Sau khi đã tạo thành công NODE (node!=NULL) chúng ta tiến hành thêm node vừa tạo vào trong danh sách.
//void InsertList(LIST& list, int data)
//{
//	NODE* p;
//	p = GetNode(data);
//	if (p != NULL)
//	{
//		Addfirst(list, p);
//	}
//}
////Để việc thêm nhiều phần tử số nguyên vào trong danh sách (liên tục). Ta tiến hành xây dựng phương thức CreateList(list).
////Phương thức này gồm 1 vòng lặp while chạy vô hạn, cho phép thực hiện việc nhập số nguyên liên tục, cho đến khi nào nhập giá trị -1 thì kết thúc.
////Khi một số nguyên được nhập, Ta tiến hành gọi phưởng thưc InsertList để thêm giá trị đó vào danh sách liên kết.
//void CreateList(LIST& list)
//{
//	InitList(list);
//	int data;
//	while (true)
//	{
//		cout << "input data: ";
//		cin >> data;
//		if (data != -1) {
//			InsertList(list, data);
//		}
//		else { break; }
//	}
//}
////Để duyệt một danh sách liên kết ta thực hiện các bước sau:
////1. khởi tạo 1 con trỏ kiểu NODE, để nắm giữ NODE đầu danh sách.
////2. Cho vòng lặp chạy cho đến khi con trỏ p trỏ đến phần tử cuối cùng trong danh sách.
////KHi thực hiện vòng lặp cần xác định 3 giá trị: giá trị khởi tạo (p=list.First), giá trị tăng (p=p->link), giá trị dừng (p!=NULL).
////3. Xử lý node tại thời điểm hiện tại của con trỏ p.
//void PrintList(LIST list)
//{
//	NODE* p;
//	p = list.first;
//	while (p!=NULL)
//	{
//		//xy ly data
//		cout << p->data<<" ";
//		//tang p sang pt tiep theo
//		p = p->link;
//	}
//}
////------------------------------Buổi học ngày 23-10-2021------------------------------
//// tích hợp menu chọn chương trình vào trong bài.
////Thực hiện các thao tác sau:
////1. In toàn bộ danh sách
////2. In danh sách số chẵn trong danh sách
//void PrintEvenNumber(LIST list)
//{
//	NODE* p;
//	p = list.first;
//	while (p != NULL)
//	{
//		if (p->data % 2 == 0)
//			cout << p->data;
//		//tang p sang pt tiep theo
//		p = p->link;
//	}
//}
//bool isPrime(int n)
//{
//	// Neu n < 2 thi khong phai la SNT
//	if (n < 2) {
//		return false;
//	}
//
//	for (int i = 2; i < (n - 1); i++) {
//		if (n % i == 0) {
//			return false;
//		}
//	}
//
//	return true;
//}
// 
////3. In danh sách số lẻ trong danh sách.
//
////4. In danh sách các số nguyên tố có trong danh sách.
//void PrintPrime(LIST list)
//{
//	NODE* p;
//	p = list.first;
//	while (p != NULL)
//	{
//		if (isPrime(p->data))
//			cout << p->data;
//		//tang p sang pt tiep theo
//		p = p->link;
//	}
//}
////5. Tìm kiếm giá trị x nhập từ bàn phím
////o tren
////6. Tìm kiếm tất cả các giá trị x có trong danh sách. đếm xem có bao nhiêu giá trị x trong danh sách.
//// Bài tập nộp về nhà
//// 
//// 7.0. Xoa mot nut sau node q
//void RemoveAfterQ(LIST& list, NODE* q)
//{
//	if (q != NULL && q->link != NULL)
//	{
//		NODE* p = q->link;
//		q->link = p->link;
//		if (p->link == NULL)//node cuoi
//			list.last = q;
//		free(p);
//	}
//}
////7.1 Xoa mot nut sau nut co gia tri x
//void RemoveAfterxValue(LIST& list, int x)
//{
//	NODE* q = Searching(list, x);
//	if (q != NULL)
//		RemoveAfterQ(list, q);
//	else
//		cout << "Not found Q";
//}
////7. Xoá giá trị x khỏi danh sách.
//void RemoveValuex(LIST& list, int x)
//{
//	NODE* p = list.first;
//	NODE* q = p;
//	while (p!=NULL)
//	{
//		if (p->data == x)
//		{
//			if (p == list.first)
//			{
//				RemoveFirst(list);
//				break;
//			}
//			else//khong phai phan tu dau
//			{
//				RemoveAfterQ(list, q);
//					break;
//			}
//		}
//		//phan tang
//		q = p;
//		p = p->link;
//	}
//}
////8. Xoá tất cả các giá trị x khỏi danh sách.
////9. xoá phần tử đầu danh sách.
//void RemoveFirst(LIST& list)
//{
//	if (list.first != NULL)
//	{
//		NODE* p = list.first;
//	
//		list.first = p->link;
//		if (list.first == NULL)
//			list.last = NULL;
//		free(p);
//	}
//}
////10 xoá toàn bộ danh sách.
//void RemoveAll(LIST& list)
//{
//	NODE* p;
//	p = list.first;
//	while (p != NULL)
//	{
//		RemoveFirst(list);
//		//tang p sang pt tiep theo
//		p = p->link;
//	}
//}
//int menu()
//{
//	system("cls");
//	cout << endl;
//	cout << setfill(' ');
//	cout << setw(55) << "-------- MENU -------" << endl;
//
//	cout << setw(55) << "| 1. Create List     |" << endl;
//	cout << setw(55) << "| 2. Print List     |" << endl;
//	cout << setw(55) << "| 3. Add x after value         |" << endl;
//	cout << setw(55) << "| 4.Remove first         |" << endl;
//	cout << setw(55) << "| 5.Exit         |" << endl;
//	cout << setw(55) << "---------------------" << endl;
//	int option;
//	cout << "Select function: ";
//	cin >> option;
//	return option;
//
//}
//void main()
//{	
//	
//	while (true)
//	{
//		LIST list;
//		int option;
//		option = menu();
//		switch (option)
//		{
//		case 1:
//			cout << setfill('-');
//			cout << setw(55) << "-" << endl;
//			cout << "Add Node:" << endl;
//			CreateList(list);
//			PrintList(list);
//			system("pause");
//			break;
//		case 2:
//			cout << setfill('-');
//			cout << setw(55) << "-" << endl;
//			cout << "Print List" << endl;
//			PrintList(list);
//			system("pause");
//			break;
//		case 3:
//			cout << "Add x After value:"<<endl;
//			int x, value;
//			cout << "input x:"; cin >> x;
//			cout << "input value:"; cin >> value;
//			AddXAfterValue(list, value, x);
//			break;
//		case 4:
//			RemoveFirst(list);
//			PrintList(list);
//			system("pause");
//			break;
//		default:
//
//			return;
//		}
//	}
//
//}
//
////Thực hiện gọi chức năng chương trình bằng Menu.