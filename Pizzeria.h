#ifndef __PIZERRIA_H
#define __PIZERRIA_H 

#include "Person.h"
#include "WorkDay.h"
#include"PizzeriaExeption.h"
#include "Vehicle.h"
#include"Worker.h"
#include "Stock.h"
#include "SpecialTasks.h"
//--------Cheak throe decleration---------//


class Pizzeria 
{
private:
	char* phoneNumber;
	int seats = 0;
	Person owner;
	Stock& stock;
	Worker* workers;
	WorkDay* workDay;
	Vehicle* vehicle;


	void setPhoneNumber(char* phoneNumber)	throw (phoneNumberExeption);
	void setOwner(Person& owner)			throw (phoneNumberExeption);

public:
	Pizzeria(char* phoneNumber, Person& owner, int seats = 0) ;
	Pizzeria(const Pizzeria& other) = delete;
	~Pizzeria();

	char* getPhoneNumber()					const { return phoneNumber; }
	int getSeats()							const { return seats; }
	Worker& getWorkerByName(const char* name)const;
	Stock& getStock()						const { return stock; }
	Worker*& getWorkers()					const;
	int getNumOfWorkers()					const;

	void setSeats(int numberOfSeats)			throw (SeatsExeption );
	void addVehicale()							throw (VehicaleExeption);
	void addWorkDay()							throw(WorkDayExeption);
	void addWorker()							throw(WorkerExeption);
	void showStock() const;
	void removeVehicle (int licenseNumber)		throw (NegetiveNumbersOfVehiacleExpration);
	void removeWork(const char* id)				throw (NegetiveNumbersOfWorkerExpration);
	void createWorkArragement()					throw (PizzeriaExeption);
	void showCurrentWorkArragement()			const;
	void show()									const;
	void addSpecialTask()						throw (NegativeNumberExeption);
	void showSpecialTasks()						const;
	friend ostream operator<<(ostream os, const Pizzeria& pizzeria);
	
};
#endif // !__PIZERRIA_H
#pragma once
