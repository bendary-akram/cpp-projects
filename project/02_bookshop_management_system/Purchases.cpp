/*
 * Purchases.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: Akram
 */

#include "Purchases.h"

Purchases::Purchases()
{
	// TODO Auto-generated constructor stub
	book_id=0;
	sup_id=0;
	qty=0;

	table_name="PURCHASE";

	stmt.str("");
	/* Create SQL statement */
	stmt << "CREATE TABLE " << '"' << table_name << '"' << "("
			"ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,"
			"BOOK_ID            INT     NOT NULL,"
			"SUP_ID            INT     NOT NULL,"
			"QTY            INT     NOT NULL);";

	db_exec();

}

Purchases::~Purchases()
{
	// TODO Auto-generated destructor stub
}

void Purchases::menu()
{
	// TODO Auto-generated constructor stub

	int c = 0;
	while (c != 6)
	{
		cout << "*************************************************" << endl;
		cout << "         Purchases Tab" << endl;
		cout << "*************************************************" << endl;
		cout << "   1. List all Purchases" << endl;
		cout << "   2. Add" << endl;
		cout << "   3. Get" << endl;
		cout << "   4. Delete" << endl;
		cout << "   5. Update Quantity" << endl;
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
			update_qty();
			break;
		case 6:
			//Exit from loop
			break;
		default:
			break;
		}
	}
}

void Purchases::add()
{

	cout << "Enter The Book ID : ";
	cin >> book_id;
	cout << "Enter The Supplier ID : " << endl;
	cin >> sup_id;
	cout << "Enter The Quantity: ";
	cin >> qty;

	stmt.str("");
	/* Create SQL statement */
	stmt << "INSERT INTO " << '"' << table_name << '"'
			<< "(BOOK_ID,SUP_ID,QTY) VALUES (" << book_id << ','
			<< sup_id << ',' << qty << "); ";

	db_exec();
}

void Purchases::update_qty()
{
	cout << "Enter The Purchase ID : ";
	cin >> id;
	cout << "Enter The new Quantity: ";
	cin >> qty;

	stmt.str("");
	/* Create SQL statement */
	stmt << "UPDATE " << '"' << table_name << '"'
			<< "SET QTY=" <<  qty << " "
			<< "WHERE  ID =" << id << ';';

	db_exec();

}
