/*
 * Books.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: Akram
 */

#include "Books.h"

int callback(void *data, int argc, char **argv, char **azColName){
   int i;

   cout <<(const char*)data<< endl;
   cout << endl;

   for(i = 0; i<argc; i++){
      cout << azColName[i] << " = "  <<(argv[i] ? argv[i] : "NULL") <<endl;
   }
   cout << endl;
   return 0;
}

Books::Books() {
	// TODO Auto-generated constructor stub
	number_pages = 0;
	id=0;
	price=0;
	zErrMsg=NULL;
	rc = sqlite3_open("./02_bookshop_management_system/bookshop.db", &db);
	if( rc ){
			sqlite3_errmsg(db);
			cout << "db connection failed" << endl;
		}else{
			cout << "db connection succeeded" << endl;

			   /* Create SQL statement */
			   sql = "CREATE TABLE BOOKS("  \
			      "ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL," \
			      "NAME           TEXT    NOT NULL," \
			      "PAGES            INT     NOT NULL," \
				  "PRICE            INT     NOT NULL);";
			   /* Execute SQL statement */
			   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
			   if( rc != SQLITE_OK ){
			      cout <<"SQL error:  "<< zErrMsg<< endl;
			   } else {
			      cout << "Table created successfully" <<endl;
			   }
		}
}

Books::~Books() {
	// TODO Auto-generated destructor stub
	sqlite3_close(db);
}

void Books::menu() {
	// TODO Auto-generated constructor stub
	int c;
	cout << "*************************************************" << endl;
	cout << "         Books Tab" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. List all BOOKS" << endl;
	cout << "   2. Add" << endl;
	cout << "   3. Delete" << endl;
	cout << "   4. Back to the previous menu " << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;

	switch (c) {
	case 1:
		this->list();
		break;
	case 2:
		this->add();
		break;
	case 3:
		this->del();
		break;
	default:
		break;
	}

}

void Books::list() {
	   const char* data = "Callback function called";

	   /* Create SQL statement */
	   sql = "SELECT * from BOOKS";

	   /* Execute SQL statement */
	   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

	   if( rc != SQLITE_OK ){
		      cout <<"SQL error:  "<< zErrMsg<< endl;
	   } else {
	      cout << "Operation done successfully" <<endl;
	   }


}
void Books::insert_row()
{
	stmt.str("");
   /* Create SQL statement */
	stmt << "INSERT INTO BOOKS (NAME,PAGES,PRICE) VALUES (" \
			<<  '"' << name  << '"' << ',' \
			<<  number_pages << ',' \
			<<  price  << "); ";

	query = stmt.str();
	sql=query.c_str();
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if( rc != SQLITE_OK ){
	      cout <<"SQL error: "<< zErrMsg<< endl;
   } else {
      cout << "Records created successfully" <<endl;
   }
}

void Books::add() {

		cout << "Enter The Book name : ";
		cin >> name;
		cout << "Enter The number of Pagees : "<<endl;
		cin >> number_pages;
		cout << "Enter The price: ";
		cin >> price;

		insert_row();
}

void Books::del() {
}

