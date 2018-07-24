#ifndef __WORKER_H

#define __WORKER_H
#define DAYS 7
#define SHIFTS 2

#include <datetimeapi.h>
#include <time.h>
#include "Order.h"
#include "Person.h"
#include "WorkDay.h"
#include "SpecialOrder.h"

class Worker : public Person
{
public:
	enum eJob {GENERL,COOK,DELIVERY_PERSON,SHIFT_SUPERVISOR};

	Worker(char* name , char* phoneNumber , char* id, time_t dateOfBirth, int hourlyWage, eJob job, Order* orders);
	~Worker();
	
	//---geters---//
	const char* getId()			const {	return id;	}
	time_t getDateOfBirth()		const { return dateOfBirth; }
	float getHourlyWage()		const { return hourlyWage; }
	int getAge()				const;
	eJob* getJob()				const { return job; }
	
	void addJob(eJob job)					throw(JobExeption);
	void removeJob(eJob job)				throw(JobExeption);
	void setHourlyWage(float hurlyWege)		throw(NegativeSalaryExeption);
	void show()								const;
	void showOrders(bool isSent)			const throw(DateTypeExeption);
	bool orderSent()						const;
	void takeProduct(const Product& product)const throw (ProductExeption);//const?
	void takeAvailableShifts();
	void takerOrder()						throw (OrderExeption);
	Order& getOrderByPhone(char* phone)		const;
	void takeSpecialOrder(int numOfWorkers = 1)	const;
	SpecialOrder& getSpecialOrderByPhone(char* phone) const;
	friend ostream& operator<<(ostream os, const WorkDay& workDay);

private: 
	char* id;
	time_t dateOfBirth;
	float hourlyWage;
	eJob* job;
	Order* orders;
	bool available[SHIFTS][DAYS];
};

#pragma once

#endif // !__WORKER_H

