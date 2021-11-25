#include <iostream>
using namespace std;

typedef int dataType;
//Khai báo cấu trúc cây nhi phân 
typedef struct node {

	dataType data;
	node* left;
	node* right;
}NODE;

typedef struct tree {
	NODE* root;
	int count;
}TREE;

void InitTree(TREE& tree)
{
	tree.root = NULL;
	tree.count = 0;
}
NODE* GetNode(dataType value)
{
	NODE* p = new NODE;

	if (p == NULL)
		exit(1);
	p->data = value;
	p->left = NULL;
	p->right = NULL;

	return p;
}
//Them mot node vao cay
void InsertTree(NODE* &root, NODE* p)
{
	if (root == NULL)
		root = p;
	else {
		if (root->data > p->data)
		{
			InsertTree(root->left, p);
		}
		else if (root->data < p->data) {
			InsertTree(root->right, p);
		}
		else {
			cout << "Co gia tri roi";
			exit(1);
		}
	}
}
void InputTree(NODE*& root, int& N) {
	cout << "Nhap phan tu N= "; cin >> N;
	dataType value;
	for (int i = 0; i < N; i++)
	{
		cout << "Nhap phan tu[" << i + 1 << "]: ";
		cin >> value;
		NODE* p = GetNode(value);
		InsertTree(root, p);
	}
}

//Ba phương thức duyệt cây sẽ giống nhau chỉ khác phân vị trí của phần xứ lý node gốc
void NLR(NODE* root) {
	if (root != NULL)
	{
		cout << root->data<<" ";
		NLR(root->left);
		NLR(root->right);
	
	}
}
void LNR(NODE* root) {
	if (root != NULL)
	{
		
		NLR(root->left);
		cout << root->data << " ";
		NLR(root->right);
	}
}
void LRN(NODE* root) {
	if (root != NULL)
	{
		
		NLR(root->left);
		NLR(root->right);
		cout << root->data << " ";
	}
}
NODE* Searching(NODE* root)
{
	dataType value;
	cout << "Nhap gia tri can tim: "; cin >> value;
	if (root == NULL)
		return NULL;
	if (root->data > value)
	{
		return Searching(root->left);
	}
	else if (root->data < value) {
		return Searching(root->right);
	}
	else {
		return root;
	}
}
//Tim node lon nhat ben trai
void TimThayThe(NODE*& root, NODE* &p)
{
	if (root->right == NULL)
	{
		p->data = root->data;
		root = root->left;
	}
	else
	{
		TimThayThe(root->right, p);
	}
}
void DeleteNode(NODE*& root, int x)
{
	if (root->data > x)
	{
		DeleteNode(root->left, x);
	}
	else if (root->data < x) {
		DeleteNode(root->right, x);
	}
	else {
		if (root->left == NULL) {
			root = root->right;
		}
		else if (root->right == NULL) {
			root = root->left;
		}
		else {
			NODE* p = root;
			TimThayThe(root->left, p);
		}
	}
}
void DeleteValue(NODE*& root)
{
	dataType value;
	cout << "nhap gia tri can xoa: "; cin >> value;
	DeleteNode(root, value);
	cout << "Danh sach sau khi xoa: ";
	NLR(root);
}
void main() {
	TREE tree;
	InitTree(tree);
	int N = 0;
	InputTree(tree.root,N);
	tree.count = N;
	cout << "\nCay co: " << tree.count;
	cout << "\ngoc truoc: ";
	LNR(tree.root);
	cout << "\ngoc giua: ";
	NLR(tree.root);
	cout << "\ngoc sau: ";
	LRN(tree.root);
	//cout << Searching(tree.root)->data;
	cout << "xoa :\n";
	DeleteValue(tree.root);
	
	system("pause");

}