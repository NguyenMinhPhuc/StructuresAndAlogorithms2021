#include "iostream"
#include "string"
#include <iomanip>

using namespace std;
int menu()
{
	system("cls");
	cout << endl;
	cout << setfill(' ');
	cout << setw(55) << "-------- MENU -------" << endl;
	
	cout << setw(55) << "| 1. Choise 1       |" << endl;
	cout << setw(55) << "| 2. Choise 2       |" << endl;
	cout << setw(55) << "| 3. Exit           |" << endl;
	cout << setw(55) << "---------------------" << endl;
	int option;
	cout << "Select function: ";
	cin >> option;
	return option;

}

void main()
{
	while (true)
	{
		
		int option;
		option = menu();
		switch (option)
		{
		case 1:
			cout << setfill('-');
			cout << setw(55) << "-" << endl;
			cout << "Select function 1"<<endl;
			//dừng màn hình cho tới khi nhấp phím bất kỳ
			system("pause");
			break;
		case 2:
			cout << setfill('-');
			cout << setw(55) << "-" << endl;
			cout << "Select function 2" << endl;
			//dừng màn hình cho tới khi nhấp phím bất kỳ
			system("pause");
			break;
		default:

			return;
		}
	}
}