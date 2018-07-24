#ifndef __Order_H
#define __Order_H
#define PIZZA_PRICE 60
#include <time.h>
#include <datetimeapi.h>
#include <iostream>
#include"OrderExeption.h"
using namespace std;

class Order
{
private: 
	char* address;
	char* phoneNumber;
	time_t timeAndDateTaken;
	int price = PIZZA_PRICE;
	char* description;
	int numOfPizzas = 1;
	bool isSent = false;

public:
	Order();
	Order(const Order& other) ;
	Order(const Order&& other);
	~Order();


	const char* getAddress()		const { return address; }
	const char* getPhoneNumber()	const { return phoneNumber; }
	const char* getDescription()	const { return description; }
	const time_t getTimeAndDate()	const { return timeAndDateTaken; }
	int getPrice()					const { return price; }
	int getNumOfPizzas()			const { return numOfPizzas; }
	
	void setAddress(char* address);
	void setPhoneNumber(char* phoneNumber)	throw (phoneNumberExeption);
	void setPrice(int price)				throw (NegativePriceExeption);
	void setDescription(char* description);
	void setNumOfPizzas(int numOfPizzas)	throw (NegativeNumberOfPizzaExpretion);
	const void showOrder();

	void orderSent() { isSent = true; }

	friend ostream& operator<<(ostream& os, const  Order order);

};


#pragma once

#endif // !__Order_H

