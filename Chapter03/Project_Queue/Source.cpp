#include "iostream"

using namespace std;

#define MAX 10

typedef int item;

typedef struct queue {
	int front, rear;//front dau: rear duoi
	item data[MAX];
	int count;
}QUEUE;

//Phuong thuc khoi tao Queue
void InitQueue(QUEUE& queue)
{
	queue.front = 0;
	queue.rear = -1;
	queue.count = 0;
}
//Phuong thuc kiem tra rong
bool IsEmpty(QUEUE queue) {
	if (queue.count == 0)
		return true;
	return false;
}
//kiem tra queue day
bool IsFull(QUEUE queue) {
	return queue.count == MAX ? true : false;
}
//Phuong thuc Push
void Push(QUEUE& q, item x){
	if (IsFull(q)) {
		cout << "QUEUE FULL";
	}
	else {
		//gan phan tu x vao vi tri rear+1
		q.data[++q.rear] = x;
		q.count++;
	}
}

item Pop(QUEUE& q) {
	item result = NULL;
	if (IsEmpty(q)) {
		cout << "Queue Empty";
	}
	else {
		result = q.data[q.front];

		for (int i = q.front; i < q.rear; i++)
		{
			q.data[i] = q.data[i + 1];
		}
		q.rear--;
		q.count--;

	}
	return result;
}

void Input(QUEUE& queue)
{
	item x;
	while (true)
	{
		if (!IsFull(queue)) {
			cout << "Nhap x: "; cin >> x;
			if (x >=0) {
				Push(queue, x);
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	}
}

void OutPut(QUEUE& queue)
{
	if (IsEmpty(queue))
		cout << "Queue Empty";
	else {
		for (int i = queue.front; i <= queue.rear; i++)
		{
			cout << queue.data[i]<<" ";
		}
	}
}
void PushCircular(QUEUE &queue,item x) {
	if (IsFull(queue)) {
		cout << "Queue day";
	}
	else
	{
		queue.data[(++queue.rear) % MAX] = x;
		queue.count++;
	}
}
item PopCircular(QUEUE& queue)
{
	item result = NULL;
	if (IsEmpty(queue))
	{
		cout << "Queue roong";
		result = queue.data[queue.front];
		queue.front = (queue.front++) % MAX;
		queue.count--;
	}
	return result;
}
void main()
{
	QUEUE q;
	InitQueue(q);
	Input(q);
	OutPut(q);

	system("pause");
}