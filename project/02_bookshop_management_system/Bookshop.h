/*
 * Bookshop.h
 *
 *  Created on: Jan 30, 2022
 *      Author: Akram
 */

#ifndef BOOKSHOP_MANAGEMENT_SYSTEM_BOOKSHOP_H_
#define BOOKSHOP_MANAGEMENT_SYSTEM_BOOKSHOP_H_

#include <iostream>
#include "..\sqlite3\sqlite3.h"
#include <sstream>

using namespace std;

class Bookshop
{
private:
	char *zErrMsg;
	int id;
	string query;
	char const *sql;

protected:
	string table_name;
	stringstream stmt;
	sqlite3 *db;

public:

	//sqlite3_stmt *sql;

	Bookshop();
	virtual ~Bookshop();
	void del();
	void get_row();
	void list();
	void db_exec();

};

#endif /* 02_BOOKSHOP_MANAGEMENT_SYSTEM_BOOKSHOP_H_ */
