/*
 * Books.h
 *
 *  Created on: Jan 27, 2022
 *      Author: Akram
 */

#ifndef BOOKSHOP_MANAGEMENT_SYSTEM_BOOKS_H_
#define BOOKSHOP_MANAGEMENT_SYSTEM_BOOKS_H_

#include <iostream>
#include "..\sqlite3\sqlite3.h"
#include <sstream>

using namespace std;

class Books {
private:
	sqlite3 *db;
	int rc;
	char const * sql;
	//sqlite3_stmt *sql;
	char *zErrMsg;

	stringstream stmt;
	string query;

	int id;
	string name;
	int number_pages;
	int price;

	void insert_row(void);

public:
	Books();
	virtual ~Books();
	void menu();
	void list();
	void add();
	void del();

};


#endif /* 02_BOOKSHOP_MANAGEMENT_SYSTEM_BOOKS_H_ */
