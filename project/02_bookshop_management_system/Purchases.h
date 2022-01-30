/*
 * Purchases.h
 *
 *  Created on: Jan 30, 2022
 *      Author: Akram
 */

#ifndef BOOKSHOP_MANAGEMENT_SYSTEM_PURCHASES_H_
#define BOOKSHOP_MANAGEMENT_SYSTEM_PURCHASES_H_

#include "Bookshop.h"



class Purchases : public Bookshop {
private:
	int book_id;
	int sup_id;
	int qty;
public:
	Purchases();
	virtual ~Purchases();
	void menu();
	void add();
	void update_qty();
};


#endif /* 02_BOOKSHOP_MANAGEMENT_SYSTEM_PURCHASES_H_ */
