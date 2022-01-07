////-Mã hàng : chuỗi gồm tối đa 5 kí tự
////- Tên hàng : chuỗi gồm tối đa 20 kí tự
////- Số lượng tồn : số nguyên
////- Đơn giá : số thực
//
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//typedef struct sanpham {
//	string maSP;
//	string tenSP;
//	int soLuong;
//	float dongia;
//}SP;
//
//typedef struct node {
//	SP data;
//	node* left;
//	node* right;
//}NODE;
//
//typedef struct tree {
//	NODE* root;
//	int count;
//}T;
//
//void Init(T& tree)
//{
//	tree.root = NULL;
//	tree.count = 0;
//}
//NODE* GetNode(SP value)
//{
//	NODE* p = new NODE;
//	if (p != NULL)
//	{
//		p->data = value;
//		p->left = NULL;
//		p->right = NULL;
//	}
//}
//void InsertTree(NODE*& root, NODE* p)
//{
//	if (root == NULL)
//		root = p;
//	else {
//		if (root->data.maSP > p->data.maSP)
//		{
//			InsertTree(root->left, p);
//		}
//		else if (root->data.maSP < p->data.maSP)
//		{
//			InsertTree(root->left, p);
//		}
//		else {
//			cout << "node existed";
//		}
//	}
//}
//SP EnterProduct() {
//	SP _sanPham;
//	cin.ignore();
//	cout << "MaSP: ";
//	getline(cin, _sanPham.maSP);
//	cout << "tenSP: ";
//	getline(cin, _sanPham.tenSP);
//	cout << "SL: "; cin >> _sanPham.soLuong;
//	cout << "DG: "; cin >> _sanPham.dongia;
//	return _sanPham;
//}
//void InputTree(NODE*& root)
//{
//	char option;
//	SP _sanPham;
//	while (true)
//	{
//		_sanPham = EnterProduct();
//		NODE* p = GetNode(_sanPham);
//		InsertTree(root, p);
//		cout << " Option (y/n): "; cin >> option;
//		if (option == 'n')
//			break;
//	}
//}
//void PrintSanPham(SP data)
//{
//	cout << data.maSP << "-" << data.tenSP << "-" << data.soLuong << "-" << data.dongia << "-" << "Thanh tien: " << data.soLuong * data.dongia;
//}
//void RNL(NODE* root) {
//	if (root == NULL)
//		return;
//	RNL(root->right);
//	PrintSanPham(root->data);
//	RNL(root->left);
//}
//
//float TinhTong(NODE* root) {
//
//	float tongTien = 0;
//	if (root == NULL)
//		return;
//	return tongTien + TinhTong(root->right);
//	tongTien = root->data.soLuong * root->data.dongia;
//	return tongTien + TinhTong(root->left);
//}
//
//void main()
//{
//	T tree;
//	Init(tree);
//	InputTree(tree.root);
//	RNL(tree.root);
//
//	cout << TinhTong(tree.root);
//
//	system("pause");
//}