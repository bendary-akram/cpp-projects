/*
 * Suppliers.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: Akram
 */

#include "Suppliers.h"

Suppliers::Suppliers()
{
	// TODO Auto-generated constructor stub
	name = "";
	phn = 0;
	table_name = "SUPPLIERS";

	stmt.str("");
	/* Create SQL statement */
	stmt << "CREATE TABLE " << '"' << table_name << '"' << "("
			"ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL,"
			"NAME           TEXT    NOT NULL,"
			"PHONE            INT     NOT NULL);";

	db_exec();

}

Suppliers::~Suppliers()
{
	// TODO Auto-generated destructor stub

}

void Suppliers::menu()
{
	// TODO Auto-generated constructor stub

	int c = 0;
	while (c != 5)
	{
		cout << "*************************************************" << endl;
		cout << "         Supplier Tab" << endl;
		cout << "*************************************************" << endl;
		cout << "   1. List all Suppliers" << endl;
		cout << "   2. Add" << endl;
		cout << "   3. Get" << endl;
		cout << "   4. Delete" << endl;
		cout << "   5. Back to the previous menu " << endl << endl << endl;
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
			//Exit from loop
			break;
		default:
			break;
		}
	}
}

void Suppliers::add()
{

	cout << "Enter The Supplier name : ";
	cin >> name;
	cout << "Enter The Mobile number : ";
	cin >> phn;

	stmt.str("");
	/* Create SQL statement */
	stmt << "INSERT INTO " << '"' << table_name << '"'
			<< "(NAME,PHONE) VALUES (" << '"' << name << '"' << ',' << phn
			<< "); ";

	db_exec();
}
