#pragma once
#ifndef __PRODUCT_H
#define __PRODUCT_H

#include"Freezer.h"
#include"Person.h"
#include "PizzeriaExeption.h"
#include <iostream>

using namespace std;
class Product
{

public:

	enum eProductType {DOUGH,DRINK,MATERIAL,MAINTENANCE_PRODUCTS};

	Product(char* name, float price, int minimunAmount,
		eProductType type, Person&  supplier,
		 Freezer freezer ,bool needToOrder = false) throw (ProductExeption);
	Product(const Product& other);
	Product(const Product&& other);
	~Product();

	float getPrice()				const { return price; }
	bool getNeedToOrder()			const { return needToOrder; }
	int getMinimumAnount()		const { return minimunAmount; }
	eProductType getProductType()		const { return type; }
	const Person& getSupplier()			const { return supplier; }
	const char* getName()				const { return name; }

	void setPrice(int price)				throw(NegativePriceExeption);
	void setNeedToOrder(bool needToOrder);
	void setMinimumAmount(int minimumAmount)throw(NegativePriceExeption);

	friend ostream& operator<<(ostream& os, const  Product product);



private:

	char* name;
	float price;
	bool needToOrder;
	int minimunAmount;
	eProductType type;
	Person supplier;
	Freezer* freezer;
};
#endif // !__PRODUCT_H
