#include "iostream"
using namespace std;

int menu()
{
	int option;
	cout << "\n1. init Stack";
	cout << "\n2. Check stack";
	cout << "\n3. Push";
	cout << "\n4. Pop";
	cout << "Select Function: "; cin >> option;
	return option;
}
#define max 100
typedef int item;

typedef struct stack {
	int count;
	int top;
	item data[max];
}STACK;
void InitStack(STACK& stack)
{
	stack.count = 0;
	stack.top = 0;
}
bool IsEmpty(STACK stack) {
	if (stack.top == 0)
		return true;
	return false;
}
bool IsFull(STACK stack) {
	if (stack.top == max)
		return true;
	return false;
}
void Push(STACK& stack, int x)
{
	if (!IsFull(stack))
	{
		stack.data[stack.top] = x;
		stack.top++;//stack.top=stack.top+1
		stack.count++;
	}
	else {
		cout << "Stack full";
	}
}
item Pop(STACK& stack)
{
	item data=NULL;
	if (!IsEmpty(stack))
	{
		stack.top--;
		data = stack.data[stack.top];
		stack.count--;
	}
	return data;
}
//co so nho hon 10
void DoiCoSo(STACK & stack, int y,int coSo)
{
	int mod;
	if (y >= 0)
	{
		do {
			mod = y % coSo;
			Push(stack, mod);
			y = y / coSo;
		} while (y!=0);
	}
	while (!IsEmpty(stack))
	{
		cout << Pop(stack);
	}
}
//co so nho hon = 10
void DoiCoSo( int y, int coSo)
{
	int mod;
	STACK stack;
	InitStack(stack);
	if (y >= 0)
	{
		do {
			mod = y % coSo;
			Push(stack, mod);
			y = y / coSo;
		} while (y != 0);
	}
	while (!IsEmpty(stack))
	{
		cout << Pop(stack);
	}
}
//he 16: 0, 1, 2, 3, 4, 5, 6 ,7 ,8 ,9 ,10, a(11) ,b(12), c (13), d (14), e (15) ,f (16)
void main() {
	STACK stack;
	InitStack(stack);
	DoiCoSo(stack, 124, 2);
	DoiCoSo(125, 16);
	system("pause");
}