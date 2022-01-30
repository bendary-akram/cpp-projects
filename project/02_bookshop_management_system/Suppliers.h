/*
 * Suppliers.h
 *
 *  Created on: Jan 30, 2022
 *      Author: Akram
 */

#ifndef BOOKSHOP_MANAGEMENT_SYSTEM_SUPPLIERS_H_
#define BOOKSHOP_MANAGEMENT_SYSTEM_SUPPLIERS_H_

#include "Bookshop.h"

class Suppliers: public Bookshop
{
private:
	string name;
	long int phn;
public:
	Suppliers();
	virtual ~Suppliers();

	void menu();
	void add();
	void update_phone();
};

#endif /* 02_BOOKSHOP_MANAGEMENT_SYSTEM_SUPPLIERS_H_ */
