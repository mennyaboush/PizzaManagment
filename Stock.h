#pragma once
#ifndef __STOCK_H
#define __STOCK_H

#include<iostream>
#include"Product.h"
#include"Freezer.h"
#include"PizzeriaExeption.h"
using namespace std;

class Stock
{

public:
	enum eProductType {DOUGH,DRINK,MATERIAL,MAINTENANCE_PRODUCTS};

	Stock(Product *products = nullptr, Freezer *freezer = nullptr);
	Stock(const Stock& other) = delete;
	~Stock();

	int getFreezersCapacity()				const;
	int getFreezerCapacity(int freezerId)	const;
	Freezer& getFreezer(int freezerId)		const throw(FreezerExeption);

	void addProduct()							throw(ProductExeption);
	void removeProduct(const Product& product)	throw(ProductDoesNotExistExeption);
	void addFreezer()							throw(FreezerExeption);
	void removeFreezer(int freezerId)			throw(FreezerDoesNotExistExeption);
	Product getProductByName(const char* name);
	void showProductByType(const eProductType type)		const;
	void showProductBySupplier(const char* supplierName)const;
	void showProductsToOrder()							const;

	const Stock& operator+=(const Product& product);
	const Stock& operator+=(const Freezer& freezer);

	const Stock& operator-=(const Product& product);
	const Stock& operator-=(const Freezer& freezer);

	friend ostream& operator<<(ostream& os, const  Stock& shift);


private:
	Product *pruducts; // need to store on map.(or something like that) or whrite amount to product/
	Freezer *freezer;
	eProductType type;
};
#endif // !__STOCK_H
