/*
 * Books.h
 *
 *  Created on: Jan 27, 2022
 *      Author: Akram
 */

#ifndef BOOKSHOP_MANAGEMENT_SYSTEM_BOOKS_H_
#define BOOKSHOP_MANAGEMENT_SYSTEM_BOOKS_H_

#include "Bookshop.h"

class Books: public Bookshop
{
private:
	string name;
	int number_pages;
	int price;

public:
	Books();
	virtual ~Books();
	void menu();
	void add();
	void update_price();
};

#endif /* 02_BOOKSHOP_MANAGEMENT_SYSTEM_BOOKS_H_ */
