#include "iostream"
#include "string"
#include "iomanip"
using namespace std;
//Phương thức tạo menu chương trình quản lý sinh viên
int menu()
{
	int option=0;
	cout << "1. Input student" << endl;
	cout << "2. Input student List" << endl;
	cout << "3. Searching Student by ID" << endl;
	cout << "4. Update Student Infor" << endl;
	cout << "5. Delete Student by ID" << endl;
	cout << "6. Get the list of unclassified students" << endl;
	cout << "7. Exit" << endl;
	cout << "Select Function: ";
	cin >> option;
	return option;
}
//Tạo kiểu dữ liệu student để lưu trữ những thông tin của sinh viên
typedef struct student
{
	int ID;
	string FullName;
	string Birthday ;
	string Address;
	string Class;
}STUDENT;
//Định nghĩa một kiểu dữ liệu là dataType kiểu Student.
typedef STUDENT dataType;
//1. Phương thức nhập thông tin cho 1 sinh viên
dataType InPutStudent()
{
	dataType st;
	cout << "ID : "; cin >> st.ID;
	cout << "Full Name: "; 
	cin.ignore();
	getline(cin, st.FullName);
	cout << "Birthday : ";
	getline(cin, st.Birthday);
	cout << "Address : ";
	getline(cin, st.Address);
	cout << "Class : ";
	getline(cin, st.Class);
	return st;
}
//2. Phương thức xuất thông tin một sinh viên
void OutPutStudent(dataType sv,int row)
{
	if (row == 0)
	{
		cout << setw(5) << left << "ID";
		cout << setw(30) << left << "| FullName";
		cout << setw(30) << left << "| Birthday";
		cout << setw(20) << left << "| Address";
		cout << setw(10) << left << "| Class" << endl;
		cout << setfill('-');		
		cout << setw(95) << "-" << endl;
	}
	// reset fill bằng ký tự ' '
	cout << setfill(' ');
	cout << setw(5) << left << sv.ID;
	cout << setw(30) << left << sv.FullName;
	cout << setw(30) << left << sv.Birthday;
	cout << setw(20) << left  << sv.Address;
	cout << setw(10) << left  << sv.Class << endl;
}
//Tạo cấu trúc node cho danh sách liên kết
typedef struct node
{
	dataType data;//Thành phần Data
	node* link;//Thành phần Link
}NODE;//Đặt tên kiểu NODE
//Định nghĩa kiểu con trỏ NODE
typedef NODE *ptrNode;
//Định nghĩa cấu trúc 1 danh sách liên kết đơn
typedef struct list{
	ptrNode first;
	ptrNode last;
}LIST;
//Phương thức khởi tạo danh sách
void InitList(LIST &list)
{
	list.first = list.last = NULL;
}
//Phương thức Tạo một node chứa kiểu dữ liệu sinh viên
ptrNode GetNode(dataType student)
{
	ptrNode p = new NODE;// Khai báo và khởi tạo vùng nhớ kiểu NODE
	if (p == NULL)
		exit(1);
	p->data = student;
	p->link = NULL;

	return p;
}
//Phương thức thêm một Node vào đầu danh sách
void AddFirst(LIST &list, ptrNode newNode)
{
	if (list.first == NULL)
	{
		list.first = newNode;
		list.last = list.first;
	}
	else
	{
		newNode->link = list.first;
		list.first = newNode;
	}
}
//Phương thêm một sinh viên vào danh sách
void InsertList(LIST &list, dataType student)
{
	ptrNode p = GetNode(student);
	AddFirst(list, p);
}
//Phương thức cho phép nhập một danh sách sinh viên
void CreateList(LIST &list)
{
	dataType sv;
	string option;
	do{
		sv = InPutStudent();
		InsertList(list, sv);
		cout << "Do you want to continue? (y/n): ";
		getline(cin, option);
	} while (option == "y");
}
//Phương thức in danh sách sinh viên
//Thực hiện hành động duyệt danh sách liên kết đơn
void PrintStudentsList(LIST list)
{
	ptrNode p = list.first;
	int i = 0;
	while (p!=NULL)
	{
		OutPutStudent(p->data,i++);
		p = p->link;
	}
}
//Phương thức tìm kiếm sinh viên theo mã số sinh viên.
void SearchingStudentByID(LIST list)
{
	int ID;
	cout << "Input ID: "; cin >> ID;

	ptrNode p = list.first;
	while (p != NULL)
	{
		if (p->data.ID == ID)
		{
			OutPutStudent(p->data, 0);
			break;
		}
		p = p->link;
	}
}
//Phương thức sửa thông tin sinh viên theo mã số sinh viên
void UpdateStudent(LIST list)
{
	int ID;
	cout << "Input ID: "; cin >> ID;

	ptrNode p = list.first;
	while (p != NULL)
	{
		if (p->data.ID == ID)
		{
			cout << "Re-enter student information with ID :" << ID;
			dataType sv = InPutStudent();
			p->data = sv;
			break;
		}
		p = p->link;
	}
}
//Phương thức xoá một node sau node Q
void DeleteAfterQ(LIST &list, ptrNode q)
{
	if (q != NULL&&q->link != NULL)
	{
		ptrNode p;
		p = q->link;

		q->link = p->link;
		if (p->link == NULL)
			list.last = q;
		delete p;
	}
}
//Phương thức xoá một node đầu danh sách
void DeleteFirst(LIST &list)
{
	ptrNode p = list.first;
	if (list.first != NULL)
	{
		list.first = p->link;
		if (list.first == NULL)
			list.last = NULL;
		
		delete p;
	}
}
//Phương thức xoá một sinh viên với ID nhập từ bàn phím
void DeleteStudentByID(LIST &list)
{
	int ID;
	cout << "Nhap ma can xoa: "; cin >> ID;
	ptrNode p = list.first;
	ptrNode q = p;
	while (p != NULL)
	{
		if (p->data.ID == ID)
		{
			if (p == list.first)
			{
				DeleteFirst(list);
				break;
			}
			else{
				DeleteAfterQ(list, q);
				break;
			}
		}
		q = p;
		p = p->link;
	}
	
}
//Phương thức lấy danh sách sinh viên chưa xếp lớp
LIST GetUnclassifiedStudents(LIST list)
{
	LIST listChuaXepLop;
	InitList(listChuaXepLop);

	ptrNode p = list.first;
	while (p != NULL)
	{
		if (p->data.Class == " ")
		{
			AddFirst(listChuaXepLop, p);
			break;
		}
		p = p->link;
	}
	return listChuaXepLop;
}

void main()
{
	int option;
	LIST list;
	InitList(list);

	while (true)
	{
		option = menu();
		switch (option)
		{
		case 1:
			CreateList(list);
			break;
		case 2:
			PrintStudentsList(list);
			break;
		case 3:
			SearchingStudentByID(list);
			break;
		case 4:
			UpdateStudent(list);
			break;
		case 5:DeleteStudentByID(list);
			break;
		case 6:
			LIST list1;
			InitList(list1);
			list1 = GetUnclassifiedStudents(list);
			PrintStudentsList(list1); 
			break;
		case 7:
			return;
		}
	}
	system("pause");
}