//để bài :
//in toàn bộ danh sách
//in danh sách các số chẵn lẻ , số nguyên tố
//tìm kiếm giá trị x nhập từ bàn phím
//tìm kiếm tất cả các giá trị x trong danh sách có bao giá trị
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
typedef struct node {
	int data; // thành phần dữ liệu
	node* link; // thành phần liên kết
}NODE;
typedef struct list {
	NODE* first;
	NODE* last;
}LIST;
void Init(LIST& list) {
	list.first = list.last = NULL;
}
//tạo 1 node động
NODE* GetNode(int data) {
	NODE* p;
	p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL)
	{
		exit(1);
	}
	p->data = data;
	p->link = NULL;
	return p;
}
void AddFirst(LIST& list, NODE* new_node) {
	if (list.first == NULL) {//danh sach rong
		list.first = new_node;
		list.last = list.first;
	}
	else {
		new_node->link = list.first;
		list.first = new_node;
	}
}
void AddLast(LIST& list, NODE* new_node) {
	if (list.first == NULL) {
		list.first = new_node;
		list.last = list.first;
	}
	else
	{
		list.last->link = new_node;
		list.last = new_node;
	}
}
void InsertList(LIST& list, int data, int option) {
	NODE* p;
	p = GetNode(data);
	if (p != NULL) {
		if (option == 1) {
			AddLast(list, p);
		}
		else
		{
			AddFirst(list, p);
		}
	}
}
void CreateList(LIST& list, int option) {
	if (option == 1) {
		Init(list);
		int data;
		while (true)
		{
			cout << "Input Data : ";
			cin >> data;
			if (data != -1) {
				InsertList(list, data, 0);//them vao duoi
			}
			else
			{
				break;
			}
		}
	}
}
void PrintList(LIST list) {
	NODE* p = list.first;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}
}
//tim so chan
void EvenNumber(LIST list) {
	for (NODE* p = list.first; p != NULL; p = p->link) {
		if (p->data % 2 == 0) {
			cout << p->data << " ";
		}
	}
}
// tim so le
void OodNumber(LIST list) {
	NODE* p = list.first;
	while (p != NULL)
	{
		if (p->data%2!=0)
		{
			cout << p->data;
		}
		p = p->link;
	}
}
// tìm số nguyên tố
int Isprime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt((float)n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int coutIsPrime(LIST list) {
	NODE* p;
	p = list.first;
	int dem = 0;
	while (p != NULL)
	{
		if (Isprime(p->data) == 1)
			dem++;
		p = p->link;
	}
	return dem;
}
void PrintPrime(LIST list) {

	NODE* p = list.first;
	while (p != NULL)
	{
		if (Isprime(p->data))
		{
			cout << p->data;
		}
		p = p->link;
	}
	/*for (NODE* p; p = list.first; p != NULL) {
		if (Isprime(p->data) == 1) {
			cout<< p->data;
		}
		p = p->link;
	}*/

}
// tìm kiếm trong danh sách
int Search(LIST list, int value) {
	int position = 0;
	for (NODE* p = list.first; p != NULL; p = p->link) {
		if (p->data == value) {
			return position;
		}
		++position;
	}
	return -1;
}
void main() {
	LIST l;
	//int n;
	CreateList(l, 1);
	PrintList(l);
	cout << "\n so chan : ";
	EvenNumber(l);
	cout << "\n so le : ";
	OodNumber(l);
	cout << "\n so nguyen to : ";
	PrintPrime(l);
	system("pause");
}