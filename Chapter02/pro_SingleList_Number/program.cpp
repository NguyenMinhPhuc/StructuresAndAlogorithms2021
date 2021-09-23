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
//Phương thức thực hiện thao tác thêm một node vào đầu danh sách.
//Phương thức này có 2 tham số: 1 là danh sách kiểu LIST, 2 là một con trỏ NODE nắm giữ 1 NODE (node muốn thêm vào.
//Có 2 trường học cần xử lý khi thêm 1 node vào đầu danh sách: 
// TH1: Thêm vào danh sách rỗng (first = NULL
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
//Phương thức thực hiện tác vụ thêm một giá trị data (sô nguyên) vào trong danh sách hiện có.
//Thao tác này được thực hiện như sau:
//Từ giá trị data được truyền từ tham số. Ta gọi hàm GetNode(data) để tạo một cấu trúc NODE cho danh sách liên kết đơn.
//Sau khi đã tạo thành công NODE (node!=NULL) chúng ta tiến hành thêm node vừa tạo vào trong danh sách.
void InsertList(LIST& list, int data)
{
	NODE* p;
	p = GetNode(data);
	if (p != NULL)
	{
		Addfirst(list, p);
	}
}
//Để việc thêm nhiều phần tử số nguyên vào trong danh sách (liên tục). Ta tiến hành xây dựng phương thức CreateList(list).
//Phương thức này gồm 1 vòng lặp while chạy vô hạn, cho phép thực hiện việc nhập số nguyên liên tục, cho đến khi nào nhập giá trị -1 thì kết thúc.
//Khi một số nguyên được nhập, Ta tiến hành gọi phưởng thưc InsertList để thêm giá trị đó vào danh sách liên kết.
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
//Để duyệt một danh sách liên kết ta thực hiện các bước sau:
//1. khởi tạo 1 con trỏ kiểu NODE, để nắm giữ NODE đầu danh sách.
//2. Cho vòng lặp chạy cho đến khi con trỏ p trỏ đến phần tử cuối cùng trong danh sách.
//KHi thực hiện vòng lặp cần xác định 3 giá trị: giá trị khởi tạo (p=list.First), giá trị tăng (p=p->link), giá trị dừng (p!=NULL).
//3. Xử lý node tại thời điểm hiện tại của con trỏ p.
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
//------------------------------Buổi học ngày 23-10-2021------------------------------
//Thực hiện các thao tác sau:
//1. In toàn bộ danh sách
//2. In danh sách số chẵn trong danh sách
//3. In danh sách số lẻ trong danh sách.
//4. In danh sách các số nguyên tố có trong danh sách.
//5. Tìm kiếm giá trị x nhập từ bàn phím
//6. Tìm kiếm tất cả các giá trị x có trong danh sách. đếm xem có bao nhiêu giá trị x trong danh sách.
//7. Xoá giá trị x khỏi danh sách.
//8. Xoá tất cả các giá trị x khỏi danh sách.
//9. xoá phần tử đầu danh sách.
//10 xoá toàn bộ danh sách.
void main()
{
	LIST list;
	CreateList(list);
	PrintList(list);
	system("pause");
}

//Thực hiện bài tập này thêm