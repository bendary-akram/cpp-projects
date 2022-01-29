#include <iostream>
#include "Books.h"

int main() {
	int c = 0;
	while (c != 7) {

		cout << "*************************************************" << endl;
		cout << "         BOOKSHOP MANGEMENT SYSTEM" << endl;
		cout << "*************************************************" << endl;
		cout << "   1. BOOKS" << endl;
		cout << "   2. SUPPLIERS" << endl;
		cout << "   3. PURCHASES" << endl;
		cout << "   4. EMPLOYEES" << endl;
		cout << "   5. MEMBERS" << endl;
		cout << "   6. SALES" << endl;
		cout << "   7. EXIT" << endl << endl << endl;
		cout << "Enter Your Choice : ";
		cin >> c;

		switch (c) {
		case 1:
			system("cls");
			Books book;
			book.menu();
			break;

			defualt: break;
		}
	}
	cout << "GoodBye :) ";

	return 0;
}
