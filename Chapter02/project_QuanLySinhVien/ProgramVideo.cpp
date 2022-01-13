//#include "iostream"
//#include "string"
//#include <iomanip>
//
//using namespace std;
//
//int Menu()
//{
//	int option = 0;
//	cout << "1. Input Students" << endl;
//	cout << "2. Print students" << endl;
//	cout << "3. Searching Student By ID" << endl;
//	cout << "4. Update Student by id" << endl;
//	cout << "5. Get The List of Student by Class" << endl;
//	cout << "6. Exit" << endl;
//	cout << "Select Function: "; cin >> option;
//	return option;
//}
//typedef struct student {
//	int ID;
//	string FullName;
//	string Birthday;
//	string Address;
//	string Class;
//}STUDENT;
//
//typedef STUDENT dataType;
//
//dataType InputStudent(int ID)
//{
//	dataType st;
//	st.ID = ID;
//	cout << "ID: " << ID << endl;
//
//	cin.ignore();
//	cout << "Full Name: ";
//	getline(cin, st.FullName);
//
//	cout << "Birthday: ";
//	getline(cin, st.Birthday);
//
//	cout << "Address: ";
//	getline(cin, st.Address);
//
//	cout << "Class: ";
//	getline(cin, st.Class);
//
//	return st;
//}
//void OutputStudent(dataType st,int index)
//{
//	if (index == 0) {
//		//In tieu de
//		cout << setw(5) << left << "ID";
//		cout << setw(30) << left << "| FullName";
//		cout << setw(20) << left << "| Birthday";
//		cout << setw(30) << left << "| Address";
//		cout << setw(10) << left << "| Class"<<endl;
//		cout << setfill('-');
//		cout << setw(95) << "-" << endl;
//	}
//	//chi in gia tri
//	cout << setfill(' ');
//	cout << setw(5) << left << st.ID;
//	cout << setw(30) << left << st.FullName;
//	cout << setw(20) << left << st.Birthday;
//	cout << setw(30) << left << st.Address;
//	cout << setw(10) << left << st.Class << endl;
//}
//typedef struct node {
//	dataType data;
//	node* link;
//}NODE;
//typedef NODE* ptrNODE;
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
//typedef struct list
//{
//	ptrNODE first;
//	ptrNODE last;
//}LIST;
//void InitList(LIST& list) {
//	list.first = list.last = NULL;
//}
//void AddFirst(LIST& list, ptrNODE newNODE)
//{
//	if (list.first == NULL)
//	{
//		list.first = newNODE;
//		list.last = list.first;
//	}
//	else
//	{
//		newNODE->link = list.first;
//		list.first = newNODE;
//	}
//}
//void InsertList(LIST& list, dataType st)
//{
//	ptrNODE p = GetNode(st);
//	AddFirst(list, p);
//}
//int MaxID(LIST list)
//{
//	if (list.first == NULL)
//		return 1;
//	return list.first->data.ID + 1;
//}
////5.4.2.1
//int MaxID02(LIST list)
//{
//	int maxID = 0;
//	ptrNODE p = list.first;
//	while (p != NULL)
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
//	do
//	{
//		st = InputStudent(MaxID(list));
//		cout << "Do you want to Continue? (y/n): "; 
//		getline(cin, option);
//	} while (option=="y");
//}
//void PrintStudets(LIST list)
//{
//	ptrNODE p = list.first;
//	int index = 0;
//	while (p != NULL)
//	{
//		OutputStudent(p->data, index++);
//		p = p->link;
//	}
//}
//ptrNODE SearchingStudentByID(LIST list)
//{
//	int id;
//	cout << "Input ID: "; cin >> id;
//
//	ptrNODE p = list.first;
//	
//	while (p != NULL)
//	{
//		if (p->data.ID == id)
//			return p;
//		p = p->link;
//	}
//	return NULL;
//}
//LIST SearchingStudentByClass(LIST list, string _class)
//{
//	LIST newList;
//	InitList(newList);
//	ptrNODE p = list.first;
//
//	while (p != NULL)
//	{
//		if (p->data.Class == _class)
//			InsertList(newList, p->data);
//		p = p->link;
//	}
//	return newList;
//}
//
//void UpdateStudentByID(LIST& list) {
//	int id;
//	cout << "Input ID: "; cin >> id;
//	ptrNODE p = list.first;
//	while (p != NULL)
//	{
//		if (p->data.ID == id)
//		{
//			p->data = InputStudent(id);
//			break;
//		}
//		p = p->link;
//	}
//}
//void main()
//{
//	int option = 0;
//	LIST list;
//	InitList(list);
//	while (true)
//	{
//		option = Menu();
//		switch (option)
//		{
//		case 1:
//			CreateList(list);
//			break;
//		case 2:
//			PrintStudets(list);
//			break;
//		case 3:
//			SearchingStudentByID(list);
//			break;
//		case 4:
//			UpdateStudentByID(list);
//			break;
//		case 5:
//			SearchingStudentByClass(list, " ");
//			break;
//		default:
//			return;
//		}
//	}
//	system("pause");
//}