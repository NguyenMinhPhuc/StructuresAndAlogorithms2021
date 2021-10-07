//#include "iostream"
//#include "string"
//#include "ctime"
////Thu vien cho ham setw
//#include "iomanip"
//
//using namespace std;
////Begin Student
////Khai báo cấu trúc student để lưu trữ thông tin sinh viên
//typedef struct student {
//	int ID;
//	string FullName;
//	string Birthday;
//	string Address;
//	string Class;
//}STUDENT;
//
//typedef STUDENT dataType;
////1.2.4.5.6
////120999999
//
//dataType InputStudent( int ID) {
//
//	dataType st;
//	/*cout << "ID : "; cin >> st.ID;*/
//	st.ID = ID;
//	cout << "ID: " << st.ID<<endl;
//	cout << "Full Name: ";
//	cin.ignore();
//	getline(cin, st.FullName);
//	cout << "Birthday : ";
//	getline(cin, st.Birthday);
//	cout << "Address : ";
//	getline(cin, st.Address);
//	cout << "Class : ";
//	getline(cin, st.Class);
//	return st;
//}
//void OutputStudent(dataType st, int index)
//{
//	//if (index == 0)
//	//{
//	//	cout << setw(5) << left << "ID";
//	//	cout << setw(30) << left << "| FullName";
//	//	cout << setw(30) << left << "| Birthday";
//	//	cout << setw(20) << left << "| Address";
//	//	cout << setw(10) << left << "| Class" << endl;
//	//	cout << setfill('-');
//	//	cout << setw(95) << "-" << endl;
//	//}
//	//// reset fill bằng ký tự ' '
//	//cout << setfill(' ');
//	//cout << setw(5) << left << " " << st.ID;
//	//cout << setw(30) << left << st.FullName;
//	//cout << setw(30) << left <<  st.Birthday;
//	//cout << setw(20) << left <<  st.Address;
//	//cout << setw(10) << left <<  st.Class << endl;
//	if (index == 0) {
//		cout << setw(5) << left << "ID";
//		cout << setw(30) << left << " | FullName";
//		cout << setw(30) << left << " | Birthday";
//		cout << setw(20) << left << " | Adress";
//		cout << setw(10) << left << " | Class\n";
//		cout << setfill('-');
//		cout << setw(95) << "-" << "\n";
//	}
//	cout << setfill(' ');
//	cout << setw(5) << right << st.ID;
//	cout << setw(30) << left << st.FullName;
//	cout << setw(30) << left << st.Birthday;
//	cout << setw(20) << left << st.Address;
//	cout << setw(10) << left << st.Class;
//}
////End Student
//
////begin List
//typedef struct node
//{
//	dataType data;//Thành phần Data
//	node* link;//Thành phần Link
//}NODE;
//
//typedef NODE* ptrNODE;
//
//typedef struct list {
//	NODE* first;
//	NODE* last;
//}LIST;
//
//void InitList(LIST& list)
//{
//	list.first  = NULL;
//	list.last = NULL;
//}
//
//ptrNODE GetNode(dataType st)
//{
//	ptrNODE p = new NODE;
//	if (p == NULL)
//		exit(1);
//	p->data = st;
//	p->link = NULL;
//
//	return p;
//}
//void AddFirst(LIST& list, ptrNODE new_ele)
//{
//	if (list.first == NULL)
//	{
//		list.first = new_ele;
//		list.last = list.first;
//	}
//	else
//	{
//		new_ele->link = list.first;
//		list.first = new_ele;
//	}
//}
//void InsertList(LIST& list, dataType st)
//{
//	ptrNODE new_ele = GetNode(st);
//	AddFirst(list, new_ele);
//}
//int MaxID(LIST list)
//{
//	if (list.first == NULL)
//		return 1;
//	return list.first->data.ID + 1;
//}
////76431
//int MAXID02(LIST list)
//{
//	int maxID = 0;
//	ptrNODE p = list.first;
//	while (p!=NULL)
//	{
//		if (p->data.ID > maxID)
//			maxID = p->data.ID;
//		p = p->link;
//	}
//	return maxID;
//}
//void CreateList(LIST& list)
//{
//	dataType st;
//	string option;
//	
//	do
//	{
//		st = InputStudent(MaxID(list));
//		InsertList(list, st);
//		cout << "Do you want to continue? (y/n): "; 
//		getline(cin, option);
//	} while (option=="y");
//}
//void PrintStudents(LIST list)
//{
//	ptrNODE p = list.first;
//	int i = 0;
//	while (p != NULL)
//	{
//		OutputStudent(p->data, i++);
//		p = p->link;
//	}
//}
//void SearchingStudentByID(LIST list) {
//	
//	int id;
//	cout << "Input id: "; 
//	cin >> id;
//	ptrNODE p = list.first;
//	
//	while (p != NULL)
//	{
//		if (p->data.ID == id)
//		{
//			cout << "SV ID: " << id<<endl;
//			OutputStudent(p->data,0);
//			break;
//		}
//		p = p->link;
//	}
//}
//ptrNODE SearchingStudentByID2(LIST list) {
//	int id;
//	cout << "Input id: "; cin >> id;
//	ptrNODE p = list.first;
//	dataType st;
//	while (p != NULL)
//	{
//		if (p->data.ID == id)
//		{
//			return p;
//		}
//		p = p->link;
//	}
//	return NULL;
//}
//void UpdateStudentByID(LIST& list) {
//	int id;
//	cout << "Input id: "; cin >> id;
//	ptrNODE p = list.first;
//	dataType st;
//	while (p != NULL)
//	{
//		if (p->data.ID == id)
//		{
//			cout << "Re-enter student: " << endl;
//			st = InputStudent(id);
//			p->data = st;
//			break;
//		}
//		p = p->link;
//	}
//}
////danh sach sv chưa xep lop
//LIST SearchingBYClass(LIST& list,string Class)
//{
//	LIST newList;
//	InitList(newList);
//
//	ptrNODE p = list.first;
//	while (p != NULL)
//	{
//		if (p->data.Class == Class)
//		{
//			AddFirst(newList, p);
//			/*break;*/
//		}
//
//		p = p->link;
//	}
//	return newList;
//}
//
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
//NODE* Searching(LIST& list, int x) {
//	NODE* p;
//	p = list.first;
//	while (p != NULL && p->data.ID != x)
//	{
//		p = p->link;
//	}
//	return p;
//}
//
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
////7. Xoá giá trị x khỏi danh sách.
//void RemoveValuex(LIST& list, int x)
//{
//	NODE* p = list.first;
//	NODE* q = p;
//	while (p != NULL)
//	{
//		if (p->data.ID == x)
//		{
//			if (p == list.first)
//			{
//				RemoveFirst(list);
//				break;
//			}
//			else//khong phai phan tu dau
//			{
//				RemoveAfterQ(list, q);
//				break;
//			}
//		}
//		//phan tang
//		q = p;
//		p = p->link;
//	}
//}
////End List
//
//int menu()
//{
//	int option=0;
//	cout << "1. Input student" << endl;
//	cout << "2. Print student List" << endl;
//	cout << "3. Searching Student by ID" << endl;
//	cout << "4. Update Student Infor" << endl;
//	cout << "5. Delete Student by ID" << endl;
//	cout << "6. Get the list of unclassified students" << endl;
//	cout << "7. Exit" << endl;
//	cout << "Select Function: ";
//	cin >> option;
//	return option;
//}
////Khai báo Include "ctime"
//int RandomNumber(int a,int b)
//{
//	srand(time(0));
//	return a + rand() % (b - a + 1);
//}
//void main() {
//
//	LIST list;
//	InitList(list);
//	int option=0;
//	while (true)
//	{
//		option = menu();
//		switch (option)
//		{
//		case 1:
//			CreateList(list);
//			break;
//		case 2: 
//			PrintStudents(list);
//			break;
//		case 3: 
//			SearchingStudentByID(list);
//			break;
//		case 4:
//			UpdateStudentByID(list);
//			break;
//		case 5:
//			int id;
//			cout << "Student ID: "; cin >> id;
//			RemoveValuex(list, id);
//			break;
//		case 6:
//			SearchingBYClass(list, " ");
//			break;
//		default:
//			return;
//		}
//
//	}
//	
//	system("pause");
//}
//
////#include <iostream>
////#include <string>
////#include "iomanip"
////
////using namespace std;
////
////typedef struct student {
////	int ID;
////	string FullName;
////	string Birthday;
////	string Address;
////	string Class;
////}STUDENT;
////
////typedef STUDENT dataType;
////
////dataType InputStudent(int ID) {
////	
////	dataType st;
////	st.ID = ID;
////	cout << "ID: " << ID << endl;
////	cout << "Full Name :";
////	cin.ignore();
////	getline(cin, st.FullName);
////
////	cout << "Birthday: ";
////	getline(cin, st.Birthday);
////
////	cout << "Adress: ";
////	getline(cin, st.Address);
////
////	cout << "Class: ";
////	getline(cin, st.Class);
////	return st;
////
////	
////}
////void OutPutStudent(dataType st, int index) {
////	if (index == 0) {
////		cout << setw(5) << left << "ID";
////		cout << setw(30) << left << " | FullName";
////		cout << setw(30) << left << " | Birthday";
////		cout << setw(20) << left << " | Adress";
////		cout << setw(10) << left << " | Class\n";
////		cout << setfill('-');
////		cout << setw(95) << "-" << "\n";
////	}
////	cout << setfill(' ');
////	cout << setw(5) << left << st.ID;
////	cout << setw(30) << left << st.FullName;
////	cout << setw(30) << left << st.Birthday;
////	cout << setw(20) << left << st.Address;
////	cout << setw(10) << left << st.Class;
////}
//////begin list
////typedef struct node {
////	dataType data;
////	node* link;
////}NODE;
////typedef NODE* ptrNODE;
////typedef struct list {
////	ptrNODE first;
////	ptrNODE last;
////}LIST;
////
////void InitList(LIST& list) {
////	list.first = NULL;
////	list.last = NULL;
////}
////
////ptrNODE GetNode(dataType st) {
////	ptrNODE new_ele = new NODE;
////	if (new_ele == NULL)
////		exit(1);
////	new_ele->data = st;
////	new_ele->link = NULL;
////	return new_ele;
////
////}
////void AddFirst(LIST& list, ptrNODE new_ele) {
////	if (list.first == NULL) {
////		list.first = new_ele;
////		list.last = list.first;
////	}
////	else {
////		new_ele->link = list.first;
////		list.first = new_ele;
////	}
////}
////void InsertList(LIST& list, dataType st) {
////	ptrNODE new_ele = GetNode(st);
////	AddFirst(list, new_ele);
////}
////int MaxID(LIST list) {
////	if (list.first == NULL)
////		return 1;
////	return list.first->data.ID + 1;
////}
////int MAXID02(LIST list) {
////	int maxID = 0;
////	ptrNODE p = list.first;
////	while (p != NULL)
////	{
////		if (p->data.ID > maxID)
////			maxID = p->data.ID;
////		p = p->link;
////	}
////	return maxID;
////}
////void CreateList(LIST& list) {
////	dataType st;
////	string option;
////	do
////	{
////		st = InputStudent(MaxID(list));
////		InsertList(list, st);
////		cout << "Do you want to continue ? (y/n)";
////		cin >> option;
////	} while (option == "y");
////
////}
////
////void PrintStudent(LIST& list) {
////	ptrNODE p = list.first;
////	int i = 0;
////	while (p != NULL)
////	{
////		OutPutStudent(p->data, i++);
////		p = p->link;
////	}
////}
////void SearchingStudentByID(LIST& list) {
////	int id;
////	cout << "Input ID: "; cin >> id;
////	ptrNODE p = list.first;
////	while (p != NULL)
////	{
////		if (p->data.ID == id) {
////			cout << "sv ID: " << id << "\n";
////			OutPutStudent(p->data, 0);
////			break;
////		}
////		p = p->link;
////	}
////}
////ptrNODE SearchingStudentByID2(LIST& list) {
////	int id;
////	cout << "input id: "; cin >> id;
////	ptrNODE p = list.first;
////	dataType st;
////	while (p != NULL)
////	{
////		if (p->data.ID == id) {
////			return p;
////		}
////		p = p->link;
////	}
////	return NULL;
////}
////LIST SearchingByClass(LIST& list, string Class) {
////	LIST newList;
////	InitList(newList);
////	ptrNODE p = list.first;
////	while (p != NULL)
////	{
////		if (p->data.Class == Class) {
////			AddFirst(newList, p);
////		}
////		p = p->link;
////	}
////	return newList;
////}
////void UpdateStudentByID(LIST& list) {
////	int id;
////	cout << "Input id: ";
////	cin >> id;
////	ptrNODE p = list.first;
////	dataType st;
////	while (p != NULL)
////	{
////		if (p->data.ID == id) {
////			cout << "re-enter: " << "\n";
////			st = InputStudent(id);
////			p->data = st;
////			break;
////		}
////		p = p->link;
////	}
////}
//////End list
////void main() {
////	LIST list;
////	InitList(list);
////	CreateList(list);
////	PrintStudent(list);
////	system("pause");
////}


