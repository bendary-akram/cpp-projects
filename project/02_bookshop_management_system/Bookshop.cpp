/*
 * Bookshop.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: Akram
 */

#include "Bookshop.h"

int callback(void *data, int argc, char **argv, char **azColName)
{
	int i;

	cout << "Callback function called" << endl;

	for (i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
	}
	cout << endl;
	return 0;
}

Bookshop::Bookshop()
{
	// TODO Auto-generated constructor stub
	int rc = 0;
	id = 0;
	zErrMsg = NULL;

	stmt.str("");
	db = NULL;
	sql = NULL;

	rc = sqlite3_open("./02_bookshop_management_system/bookshop.db", &db);
	if (rc)
	{
		sqlite3_errmsg(db);
		cout << "db connection failed" << endl;
	}
	else
	{
		cout << "db connection succeeded" << endl;
	}
}

Bookshop::~Bookshop()
{
	// TODO Auto-generated destructor stub
}

void Bookshop::del()
{

	cout << "Enter The ID: ";
	cin >> id;
	stmt.str("");

	/* sql = "SELECT * " \
			   "FROM BOOKS "\
			   "WHERE  ID = (SELECT MAX(ID)  FROM BOOKS); ";*/
	stmt << "DELETE FROM " << '"' << table_name << '"' << "WHERE  ID =" << id
			<< ";";
	db_exec();

}

void Bookshop::get_row()
{
	cout << "Enter The ID: ";
	cin >> id;

	stmt.str("");
	/* sql = "SELECT * " \
			   "FROM BOOKS "\
			   "WHERE  ID = (SELECT MAX(ID)  FROM BOOKS); ";*/
	stmt << "SELECT * FROM" << '"' << table_name << '"' << "WHERE  ID =" << id
			<< ";";

	db_exec();
}

void Bookshop::list()
{
	stmt.str("");
	/* Create SQL statement */
	stmt << "SELECT * from " << '"' << table_name << '"';

	db_exec();
}
void Bookshop::db_exec()
{
	int rc;

	query = stmt.str();
	sql = query.c_str();
	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK)
	{
		cout << "SQL error: " << zErrMsg << endl;
	}
	else
	{
		cout << "Operation done successfully" << endl;
	}
}
