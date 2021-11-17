#include "iostream"
using namespace std;

typedef char item;
typedef struct node {
	item data;
	node* link;
}NODE;

typedef struct stack {
	NODE* top;//con tro o dau danh sach
	int count;//bien de dem so phan tu co trong stack
}STACK;

//Phuong thuc khoi tao stack
void InitStack(STACK& stack) {
	stack.top = NULL;
	stack.count = 0;
}

//Phuong thuc kiem tra danh sach rong
bool IsEmpty(STACK stack) {
	return stack.top == NULL ? true : false;
}
//Phuong thuc PUSH
void Push(STACK& stack, item x) {
	//Code getNode()
	NODE* p = new NODE;
	if (p != NULL)
	{
		p->data = x;
		p->link = NULL;
		//Them vao dau danh sach (code AddFirst()
		if (IsEmpty(stack))
		{
			stack.top = p;
		}
		else {
			p->link = stack.top;//1. noi node vao dau
			stack.top = p;//2. cat node dau va noi vao node moi
		}
		stack.count++;
	}
}
item Pop(STACK& stack) {
	item result = NULL;
	if(!IsEmpty(stack)){ 
		NODE* p = stack.top;

		result = p->data;
		stack.top = p->link;

		delete p;

		stack.count--;
	}
	return result;
}

bool KiemTraBieuThuc(string bieuThuc)
{
	STACK stack;
	InitStack(stack);
	for (char item : bieuThuc)
	{
		if (item == '(' || item == '{' || item == '['){
			Push(stack, item);
		}
		else {
			if (item == ')') {
				if (Pop(stack) != '(')
					return false;
			}
			else if (item == '}') {
				if (Pop(stack) != '{')
					return false;
			}
			else  {
				if (Pop(stack) != '[')
					return false;
			}	
		}
	}
	return true;
}
void DoiCoSo(int number, int heSo)
{
	int mod;//So du
	string arrayNumber[16] = {
		"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"
	};
	STACK stack;
	InitStack(stack);
	do
	{
		mod = number % heSo;
		Push(stack, mod);
		number = number / heSo;
	} while (number!=0);
	while (!IsEmpty(stack))
	{
		cout << arrayNumber[Pop(stack)];
	}
}

void main(){

	if (KiemTraBieuThuc("{[({)]}"))
	{
		cout << "Bieu thuc dung";
	}
	else {
		cout << "Bieu thuc sai";
	}
	cout << "\nSo moi: ";
	int number=16;
	int heSo = 16;

	DoiCoSo(number, heSo);
	cout << endl;
	system("pause");
}