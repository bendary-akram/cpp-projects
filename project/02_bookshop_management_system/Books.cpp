/*
 * Books.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: Akram
 */

#include "Books.h"

Books::Books()
{
	// TODO Auto-generated constructor stub

	number_pages = 0;
	price = 0;
	table_name = "BOOKS";

	stmt.str("");
	/* Create SQL statement */
	stmt << "CREATE TABLE " << '"' << table_name << '"' << "("
			"ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,"
			"NAME           TEXT    NOT NULL,"
			"PAGES            INT     NOT NULL,"
			"PRICE            INT     NOT NULL);";

	db_exec();

}

Books::~Books()
{
	// TODO Auto-generated destructor stub
	sqlite3_close(db);
}

void Books::menu()
{
	// TODO Auto-generated constructor stub

	int c = 0;
	while (c != 6)
	{
		cout << "*************************************************" << endl;
		cout << "         Books Tab" << endl;
		cout << "*************************************************" << endl;
		cout << "   1. List all BOOKS" << endl;
		cout << "   2. Add" << endl;
		cout << "   3. Get" << endl;
		cout << "   4. Delete" << endl;
		cout << "   5. update price" << endl;
		cout << "   6. Back to the previous menu " << endl << endl << endl;
		cout << "Enter Your Choice : ";
		cin >> c;

		switch (c)
		{
		case 1:
			list();
			break;
		case 2:
			add();
			break;
		case 3:
			get_row();
			break;
		case 4:
			del();
			break;
		case 5:
			update_price();
			break;
		case 6:
			//Exit from loop
			break;
		default:
			break;
		}
	}
}

void Books::add()
{

	cout << "Enter The Book name : ";
	cin >> name;
	cout << "Enter The number of Pagees : " << endl;
	cin >> number_pages;
	cout << "Enter The price: ";
	cin >> price;

	stmt.str("");
	/* Create SQL statement */
	stmt << "INSERT INTO " << '"' << table_name << '"'
			<< "(NAME,PAGES,PRICE) VALUES (" << '"' << name << '"' << ','
			<< number_pages << ',' << price << "); ";

	db_exec();
}

void Books::update_price()
{
	cout << "Enter The Book ID : ";
	cin >> id;
	cout << "Enter The new price: ";
	cin >> price;

	stmt.str("");
	/* Create SQL statement */
	stmt << "UPDATE " << '"' << table_name << '"'
			<< "SET PRICE=" <<  price << " "
			<< "WHERE  ID =" << id << ';';

	db_exec();

}
